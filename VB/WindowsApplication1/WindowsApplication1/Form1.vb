Imports System.Net.Sockets
Imports System.Text
Imports System.Threading
Imports System.Net
Imports System.IO.Ports



Public Class Form1

    Private comport As SerialPort
    Private portname As String = "COM7"
    Private portbaud As Integer = 38400

    Dim comportQueue As Queue(Of String) = New Queue(Of String)()
    'For thread-safe calls on wonodws forms controls
    Delegate Sub SetTextCallback([text] As String)

    Public comportThread As System.Threading.Thread
    Public messageThread As System.Threading.Thread


    Private Sub initComPort()
        comport = New SerialPort(portname, portbaud, Parity.None, 8, StopBits.One)
        comport.ReadTimeout = 10000
    End Sub

    Private Sub closeComPort()
        comport.Close()
    End Sub

    Private Function readComPort() As String
        Dim retStr As String = ""

        Try
            Do
                Dim incoming As String = comport.ReadLine()
                If incoming Is Nothing Then
                    Exit Do
                Else
                    retStr &= incoming & vbCrLf
                End If
            Loop
        Catch ex As TimeoutException
            retStr = "Error: Serial Port red timed out"
        End Try

        Return retStr
    End Function

    Private Sub CheckBox1_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CheckBox1.CheckedChanged
        If CheckBox1.CheckState = CheckState.Checked Then
            ListBox1.Items.Add(":Client enable checked")
            ListBox2.Items.Add(":Client enable checked")
            Debug.Print(":Client enable checked")
            CheckBox2.Enabled = False
            ComboBox1.Enabled = True
            ComboBox1.Text = "ComPort List"
            ComboBox2.Enabled = True
            ComboBox2.Text = "BaudRate List"
            GetSerialPortNames()
            GetSerialBaudRate()
            clientMain()
        Else
            ListBox1.Items.Add(":Client enable unchecked")
            ListBox2.Items.Add(":Client enable unchecked")
            CheckBox2.Enabled = True
            ComboBox1.Text = "No ComPort"
            ComboBox1.Items.Clear()
            ComboBox1.Enabled = False
            'ComboBox1.Text.Contains("COM clear")
        End If

    End Sub

    Private Sub CheckBox2_CheckedChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles CheckBox2.CheckedChanged
        If CheckBox2.CheckState = CheckState.Checked Then
            ListBox1.Items.Add(":Server enable checked")
            ListBox2.Items.Add(":Server enable checked")
            CheckBox1.Enabled = False
            TextBox1.Enabled = True
            TextBox1.Text = getOwnIp()
            'TextBox1.Text = "255.255.255.255"
            TextBox2.Text = "port 3388"
            TextBox2.Enabled = True
            'ListBox2.Items.Add(":About to network...")
            'serverMain()
        Else
            ListBox1.Items.Add(":Server enable unchecked")
            ListBox2.Items.Add(":Server enable unchecked")
            CheckBox1.Enabled = True
            TextBox1.Text = "255.255.255.255"
            TextBox1.Enabled = False
            TextBox2.Text = "port 3388"
            TextBox2.Enabled = False
        End If
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
        ListBox1.Items.Add(":get user select " + ComboBox1.Text)
        btnStart.Enabled = True
    End Sub

    Private Sub ComboBox2_SelectedIndexChanged(sender As System.Object, e As System.EventArgs) Handles ComboBox2.SelectedIndexChanged
        ListBox1.Items.Add(":get user select " + ComboBox2.Text)
        portbaud = ComboBox2.Text
        ListBox1.Items.Add(":get user select " + portbaud.ToString)
        'btnStart.Enabled = True
    End Sub

    Private Sub GetSerialPortNames()
        ' Show all available COM ports.
        Debug.Print("GetSerialPortNames")
        For Each sp As String In My.Computer.Ports.SerialPortNames
            ListBox1.Items.Add(":" + sp)
            Debug.Print(":" + sp)
            ComboBox1.Items.Add(sp)
        Next
    End Sub

    Private Sub GetSerialBaudRate()
        Debug.Print("GetSerialBaudRate")
        ComboBox2.Items.Add(115200)
        ComboBox2.Items.Add(57600)
        ComboBox2.Items.Add(38400)
        ComboBox2.Items.Add(19200)
        ComboBox2.Items.Add(14400)
        ComboBox2.Items.Add(9600)
    End Sub

    Private Function getOwnIp() As String
        Dim myIPaddress As String = Nothing
        Dim tmpHostName As String = System.Net.Dns.GetHostName()
        myIPaddress = System.Net.Dns.GetHostByName(tmpHostName).AddressList(0).ToString()
        Return myIPaddress
    End Function

    Private Sub comportThreadsub()
        'SyncLock GetType(comportLockObj)
        'comportJobDone += 1
        'End SyncLock
    End Sub

    'For thread-safe calls on wonodws forms controls
    Private Sub AddList1Text(ByVal [text] As String)
        If Me.ListBox1.InvokeRequired Then
            Dim d As New SetTextCallback(AddressOf AddList1Text)
            Me.Invoke(d, New Object() {[text]})
        Else
            Me.ListBox1.Items.Add([text])
        End If
    End Sub

    Private Sub messageThreadSub()
        Do
            Debug.Print("messageThreadSub")
            If Me.comportQueue.Count > 0 Then
                'ListBox1.Items.Add(comportQueue.Dequeue())
                'For thread-safe calls on wonodws forms controls
                Me.AddList1Text(comportQueue.Dequeue())
            End If
            Thread.Sleep(100)
        Loop
    End Sub


    Private Function clientMain() As Integer
        Dim myIPEndPoint As New IPEndPoint(IPAddress.Any, 0)
        Dim myTcpClient As TcpClient = New TcpClient(myIPEndPoint)
        Dim ServerIpAddress As IPAddress
        Dim iPort As Integer
        'ServerIpAddress = IPAddress.Parse("192.168.1.109")
        ServerIpAddress = IPAddress.Parse("192.168.2.111")
        iPort = 3388
        Dim RemoteIpEndPoint As New IPEndPoint(ServerIpAddress, iPort)

        Try
            myTcpClient.Connect(RemoteIpEndPoint)
            Do
                If myTcpClient.Connected = True Then
                    MsgBox("Server Connected")
                    Exit Do
                End If
            Loop
        Catch ex As Exception
            MessageBox.Show(ex.ToString)
        End Try

        Return 0
    End Function

    Private Function serverMain() As Integer
        Dim serverSocket As New TcpListener(IPAddress.Any, 3388)
        Dim requestCount As Integer
        Dim clientSocket As TcpClient

        'msg("Server Starting")
        'ListBox2.Items.Add(":" + "Server Starting")
        MsgBox("Server Starting")
        serverSocket.Start()
        'msg("Server Started")
        'ListBox2.Items.Add(":" + "Server Started")
        MsgBox("Server Started")

        'msg("About to accept connection from client")
        'ListBox2.Items.Add(":" + "About to accept connection from client")
        MsgBox("About to accept connection from client")
        clientSocket = serverSocket.AcceptTcpClient()
        'msg("Accept connection from client")
        'ListBox2.Items.Add(":" + "Accept connection from client")
        MsgBox("Accept connection from client")
        requestCount = 0

        While (True)
            Try
                requestCount = requestCount + 1
                Dim networkStream As NetworkStream = clientSocket.GetStream()
                Dim bytesFrom(10024) As Byte

                networkStream.Read(bytesFrom, 0, CInt(clientSocket.ReceiveBufferSize))

                Dim dataFromClient As String = System.Text.Encoding.ASCII.GetString(bytesFrom)
                dataFromClient = dataFromClient.Substring(0, dataFromClient.IndexOf("$"))
                'msg("Data from client -  " + dataFromClient)
                'ListBox2.Items.Add(":" + "Data from client -  " + dataFromClient)
                MsgBox("Data from client -  " + dataFromClient)
                Dim serverResponse As String = "Server response " + Convert.ToString(requestCount)
                Dim sendBytes As [Byte]() = Encoding.ASCII.GetBytes(serverResponse)
                networkStream.Write(sendBytes, 0, sendBytes.Length)
                networkStream.Flush()
                'msg(serverResponse)
                'ListBox2.Items.Add(":" + serverResponse)
                MsgBox(serverResponse)
            Catch ex As Exception
                MsgBox(ex.ToString)
            End Try
        End While
        'clientSocket.Close()
        'serverSocket.Stop()
        'msg("exit")
        Return 0
    End Function

    Private Sub TextBox1_TextChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles TextBox1.TextChanged

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Dim iPort As Integer = 3388
        'Dim ListenThread As New Thread(AddressOf StartListen)
        Dim ListenThread As New Thread(AddressOf serverMain)
        ListenThread.IsBackground = True
        ListenThread.Start()
    End Sub

    Private Sub btnStart_Click(sender As System.Object, e As System.EventArgs) Handles btnStart.Click
        btnStart.Enabled = False
        ComboBox1.Enabled = False
        ComboBox2.Enabled = False
        btnStop.Enabled = True

        'initComPort()
        'readComPort()

        SerialPort1.DataBits = 8
        SerialPort1.StopBits = StopBits.One
        SerialPort1.PortName = portname
        SerialPort1.BaudRate = portbaud
        SerialPort1.Open()

        Me.messageThread = New System.Threading.Thread(AddressOf Me.messageThreadSub)
        Me.messageThread.Start()
    End Sub

    Private Sub btnStop_Click(sender As System.Object, e As System.EventArgs) Handles btnStop.Click
        btnStart.Enabled = True
        ComboBox1.Enabled = True
        ComboBox2.Enabled = True
        btnStop.Enabled = False

        'closeComPort()
        SerialPort1.Close()

        messageThread.Abort()
    End Sub

    Private Sub SerialPort1_DataReceived(sender As Object, e As System.IO.Ports.SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        If SerialPort1.IsOpen() Then
            Dim buff() As Byte
            Dim str As String
            Dim j As Integer

            ReDim buff(SerialPort1.BytesToRead - 1)
            SerialPort1.Read(buff, 0, buff.Length)
            For i As Integer = 0 To buff.Length - 1
                str += buff(i).ToString("X2")
                If j < 22 Then
                    j = j + 1
                End If
            Next
            Debug.Print(str)
            'ListBox1.Items.Add(str)
            comportQueue.Enqueue(str)
        Else
            Debug.Print("SerialPort not open yet!!")
        End If
    End Sub
End Class
