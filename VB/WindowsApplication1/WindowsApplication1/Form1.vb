﻿Imports System.Net.Sockets
Imports System.Text
Imports System.Threading
Imports System.Net
Imports System.IO.Ports


Structure sComPortSet
    Public s_comport As SerialPort
    Public s_portname As String
    Public s_portbaud As Integer
End Structure

Structure sTcpClientSet
    Public s_IPEndPoint As IPEndPoint
    Public s_TcpClient As TcpClient
    Public s_ServerIpAddress As IPAddress
    Public s_iPort As Integer
    Public s_RemoteIPEndPoint As IPEndPoint
End Structure

Structure sTcpServerSet
    Public s_ServerSocket As TcpListener
    Public s_ClientSocket As TcpClient
    Public s_iPort As Integer
    Public s_NetStream As NetworkStream
End Structure

Public Class Form1

    Dim pv_ComPortData As sComPortSet = New sComPortSet With {.s_portname = "COM7", .s_portbaud = 38400}

    'Private comport As SerialPort
    'Private portname As String = "COM7"
    'Private portbaud As Integer = 38400

    Dim pv_NetClient As sTcpClientSet = New sTcpClientSet
    'Dim myIPEndPoint As New IPEndPoint(IPAddress.Any, 0)
    'Dim myTcpClient As TcpClient = New TcpClient(myIPEndPoint)

    Dim pv_NetServer As sTcpServerSet = New sTcpServerSet With {.s_iPort = 3388}

    Dim comportQueue As Queue(Of String) = New Queue(Of String)()
    Dim serverQueue As Queue(Of String) = New Queue(Of String)()

    'For thread-safe calls on wonodws forms controls
    Delegate Sub SetTextCallback([text] As String)

    Public comportThread As System.Threading.Thread
    Public message1Thread As System.Threading.Thread
    Public message2Thread As System.Threading.Thread


    Private Sub initComPort()
        pv_ComPortData.s_comport = New SerialPort(pv_ComPortData.s_portname, pv_ComPortData.s_portbaud, Parity.None, 8, StopBits.One)
        pv_ComPortData.s_comport.ReadTimeout = 10000
        'comport = New SerialPort(portname, portbaud, Parity.None, 8, StopBits.One)
        'comport.ReadTimeout = 10000
    End Sub

    Private Sub closeComPort()
        pv_ComPortData.s_comport.Close()
        'comport.Close()
    End Sub

    Private Function readComPort() As String
        Dim retStr As String = ""

        Try
            Do
                Dim incoming As String = pv_ComPortData.s_comport.ReadLine()
                'Dim incoming As String = comport.ReadLine()
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
            CheckBox3.Enabled = True
            CheckBox4.Enabled = True
            ComboBox1.Enabled = True
            ComboBox1.Text = "ComPort List"
            ComboBox2.Enabled = True
            ComboBox2.Text = "BaudRate List"
            GetSerialPortNames()
            GetSerialBaudRate()
            If CheckBox4.CheckState = CheckState.Checked Then
                'clientMain()
            End If
        Else
            ListBox1.Items.Add(":Client enable unchecked")
            ListBox2.Items.Add(":Client enable unchecked")
            CheckBox2.Enabled = True
            CheckBox3.Enabled = False
            CheckBox4.Enabled = False
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
            Button1.Enabled = True
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
            Button1.Enabled = False
            TextBox1.Text = "255.255.255.255"
            TextBox1.Enabled = False
            TextBox2.Text = "port 3388"
            TextBox2.Enabled = False
        End If
    End Sub

    Private Sub ComboBox1_SelectedIndexChanged(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles ComboBox1.SelectedIndexChanged
        ListBox1.Items.Add(":get user select " + ComboBox1.Text)
        'portname = ComboBox1.Text
        pv_ComPortData.s_portname = ComboBox1.Text
        btnStart.Enabled = True
    End Sub

    Private Sub ComboBox2_SelectedIndexChanged(sender As System.Object, e As System.EventArgs) Handles ComboBox2.SelectedIndexChanged
        ListBox1.Items.Add(":get user select " + ComboBox2.Text)
        'portbaud = ComboBox2.Text
        pv_ComPortData.s_portbaud = ComboBox2.Text
        ListBox1.Items.Add(":get user select " + pv_ComPortData.s_portbaud.ToString)
        'ListBox1.Items.Add(":get user select " + portbaud.ToString)
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

    Private Sub message1ThreadSub()
        Do
            'Debug.Print("message1ThreadSub")
            If Me.comportQueue.Count > 0 Then
                Dim QueueStr As String = comportQueue.Dequeue()
                'ListBox1.Items.Add(comportQueue.Dequeue())
                'For thread-safe calls on wonodws forms controls
                'Me.AddList1Text(comportQueue.Dequeue())
                Me.AddList1Text(QueueStr)
                If CheckBox4.CheckState = CheckState.Checked Then
                    'send datao to server
                    Dim myNetworkStream As NetworkStream = pv_NetClient.s_TcpClient.GetStream()
                    'Dim myNetworkStream As NetworkStream = myTcpClient.GetStream()

                    'Dim clientGreeting As String = "Hello! this client message."
                    Dim sendBytes As [Byte]() = Encoding.ASCII.GetBytes(QueueStr)
                    myNetworkStream.Write(sendBytes, 0, sendBytes.Length)
                    myNetworkStream.Flush()
                End If
            End If
            Thread.Sleep(100)
        Loop
    End Sub

    'For thread-safe calls on wonodws forms controls
    Private Sub AddList2Text(ByVal [text] As String)
        If Me.ListBox2.InvokeRequired Then
            Dim d As New SetTextCallback(AddressOf AddList2Text)
            Me.Invoke(d, New Object() {[text]})
        Else
            Me.ListBox2.Items.Add([text])
        End If
    End Sub

    Private Sub message2ThreadSub()
        Do
            'Debug.Print("message2ThreadSub")
            If Me.serverQueue.Count > 0 Then
                'ListBox2.Items.Add(comportQueue.Dequeue())
                'For thread-safe calls on wonodws forms controls
                Me.AddList2Text(serverQueue.Dequeue())
            End If
            Thread.Sleep(100)
        Loop
    End Sub

    Private Function clientMain() As Integer
        'Dim myIPEndPoint As New IPEndPoint(IPAddress.Any, 0)
        'Dim myTcpClient As TcpClient = New TcpClient(myIPEndPoint)
        pv_NetClient.s_IPEndPoint = New IPEndPoint(IPAddress.Any, 0)
        pv_NetClient.s_TcpClient = New TcpClient(pv_NetClient.s_IPEndPoint)

        'Dim ServerIpAddress As IPAddress
        'Dim iPort As Integer
        'ServerIpAddress = IPAddress.Parse("192.168.1.109")
        'ServerIpAddress = IPAddress.Parse("192.168.2.111")
        'ServerIpAddress = IPAddress.Parse("192.168.2.109")
        'iPort = 3388
        pv_NetClient.s_ServerIpAddress = IPAddress.Parse("192.168.2.109")
        pv_NetClient.s_iPort = 3388

        pv_NetClient.s_RemoteIPEndPoint = New IPEndPoint(pv_NetClient.s_ServerIpAddress, pv_NetClient.s_iPort)
        'Dim RemoteIpEndPoint As New IPEndPoint(ServerIpAddress, iPort)

        Try
            pv_NetClient.s_TcpClient.Connect(pv_NetClient.s_RemoteIPEndPoint)
            'myTcpClient.Connect(RemoteIpEndPoint)
            Do
                'If myTcpClient.Connected = True Then
                If pv_NetClient.s_TcpClient.Connected = True Then
                    MsgBox("Server Connected")
                    Exit Do
                End If
            Loop
        Catch ex As Exception
            MessageBox.Show(ex.ToString)
        End Try

        'send hello to server
        Dim myNetworkStream As NetworkStream = pv_NetClient.s_TcpClient.GetStream()
        'Dim myNetworkStream As NetworkStream = myTcpClient.GetStream()
        Dim clientGreeting As String = "Hello! this client message."
        Dim sendBytes As [Byte]() = Encoding.ASCII.GetBytes(clientGreeting)
        myNetworkStream.Write(sendBytes, 0, sendBytes.Length)
        myNetworkStream.Flush()

        Return 0
    End Function

    Private Function serverMain() As Integer
        pv_NetServer.s_ServerSocket = New TcpListener(IPAddress.Any, pv_NetServer.s_iPort)
        'Dim serverSocket As New TcpListener(IPAddress.Any, 3388)
        Dim requestCount As Integer
        'Dim clientSocket As TcpClient

        'msg("Server Starting")
        'ListBox2.Items.Add(":" + "Server Starting")
        MsgBox("Server Starting.......")
        Debug.Print("Server Starting.......")
        pv_NetServer.s_ServerSocket.Start()
        'serverSocket.Start()
        'msg("Server Started")
        'ListBox2.Items.Add(":" + "Server Started")
        MsgBox("Server Started")
        Debug.Print("Server Started!")

        'msg("About to accept connection from client")
        'ListBox2.Items.Add(":" + "About to accept connection from client")
        MsgBox("About to accept connection from client.......")
        Debug.Print("About to accept connection from client.......")
        pv_NetServer.s_ClientSocket = pv_NetServer.s_ServerSocket.AcceptTcpClient()
        'clientSocket = serverSocket.AcceptTcpClient()
        'msg("Accept connection from client")
        'ListBox2.Items.Add(":" + "Accept connection from client")
        MsgBox("Accepted connection from client.")
        Debug.Print("Accepted connection from client.")
        requestCount = 0

        While (True)
            Try
                requestCount = requestCount + 1
                pv_NetServer.s_NetStream = pv_NetServer.s_ClientSocket.GetStream()
                'Dim networkStream As NetworkStream = clientSocket.GetStream()
                'Dim bytesFrom(1023) As Byte
                Dim bytesFrom(10024) As Byte

                pv_NetServer.s_NetStream.Read(bytesFrom, 0, CInt(pv_NetServer.s_ClientSocket.ReceiveBufferSize))
                'networkStream.Read(bytesFrom, 0, CInt(clientSocket.ReceiveBufferSize))

                Dim dataFromClient As String = System.Text.Encoding.ASCII.GetString(bytesFrom)
                'dataFromClient = dataFromClient.Substring(0, dataFromClient.IndexOf("$"))
                'msg("Data from client -  " + dataFromClient)
                'ListBox2.Items.Add(":" + "Data from client -  " + dataFromClient)
                serverQueue.Enqueue(dataFromClient)
                'MsgBox("Data from client - " + dataFromClient)
                Debug.Print("Data from client - " + dataFromClient)

                ' response for client
                'Dim serverResponse As String = "Server response " + Convert.ToString(requestCount)
                'Dim sendBytes As [Byte]() = Encoding.ASCII.GetBytes(serverResponse)
                'networkStream.Write(sendBytes, 0, sendBytes.Length)
                'networkStream.Flush()
                'msg(serverResponse)
                'ListBox2.Items.Add(":" + serverResponse)
                'MsgBox(serverResponse)
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
        Button2.Enabled = True
        Button1.Enabled = False
        Me.message2Thread = New System.Threading.Thread(AddressOf Me.message2ThreadSub)
        Me.message2Thread.Start()
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        Button1.Enabled = True
        Button2.Enabled = False
        message2Thread.Abort()
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
        SerialPort1.PortName = pv_ComPortData.s_portname
        SerialPort1.BaudRate = pv_ComPortData.s_portbaud
        'SerialPort1.PortName = portname
        'SerialPort1.BaudRate = portbaud
        SerialPort1.Open()

        Me.message1Thread = New System.Threading.Thread(AddressOf Me.message1ThreadSub)
        Me.message1Thread.Start()
        If CheckBox4.CheckState = CheckState.Checked Then
            clientMain()
        End If
    End Sub

    Private Sub btnStop_Click(sender As System.Object, e As System.EventArgs) Handles btnStop.Click
        btnStart.Enabled = True
        ComboBox1.Enabled = True
        ComboBox2.Enabled = True
        btnStop.Enabled = False

        'closeComPort()
        SerialPort1.Close()
        If CheckBox4.CheckState = CheckState.Checked Then
            message1Thread.Abort()
        End If
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

    Private Sub ListBox1_MouseEnter(sender As Object, e As System.EventArgs) Handles ListBox1.MouseEnter
        Debug.Print("ListBox1_MouseEnter!!")
        ListBox1.SelectedIndex = ListBox1.Items.Count - 1
        ListBox1.SelectedIndex = -1 '----option
    End Sub

    Private Sub ListBox1_MouseLeave(sender As Object, e As System.EventArgs) Handles ListBox1.MouseLeave
        Debug.Print("ListBox1_MouseLeave!!")

    End Sub

    Private Sub ListBox1_SelectedIndexChanged(sender As System.Object, e As System.EventArgs) Handles ListBox1.SelectedIndexChanged
        'Debug.Print("ListBox1_SelectedIndexChanged!!")
        'ListBox1.SelectedIndex = ListBox1.Items.Count - 1
    End Sub

    Private Sub ListBox1_SelectedValueChanged(sender As Object, e As System.EventArgs) Handles ListBox1.SelectedValueChanged

    End Sub

    Private Sub ListBox1_TextChanged(sender As Object, e As System.EventArgs) Handles ListBox1.TextChanged
        Debug.Print("ListBox1_TextChanged!!")
        'ListBox1.SelectedIndex = ListBox1.Items.Count - 1
    End Sub

    Private Sub ListBox1_ValueMemberChanged(sender As Object, e As System.EventArgs) Handles ListBox1.ValueMemberChanged

    End Sub

    Private Sub CheckBox3_CheckedChanged(sender As System.Object, e As System.EventArgs) Handles CheckBox3.CheckedChanged
        If CheckBox3.CheckState = CheckState.Checked Then
            Debug.Print("CheckBox3_CheckedChanged checked!!")
            Timer1.Enabled = True
        Else
            Debug.Print("CheckBox3_CheckedChanged unchecked!!")
            Timer1.Enabled = False
        End If
    End Sub

    Private Sub Timer1_Tick(sender As System.Object, e As System.EventArgs) Handles Timer1.Tick
        ListBox1.SelectedIndex = ListBox1.Items.Count - 1
        ListBox1.SelectedIndex = -1 '----option
    End Sub

    Private Sub CheckBox4_CheckedChanged(sender As System.Object, e As System.EventArgs) Handles CheckBox4.CheckedChanged
        If CheckBox4.CheckState = CheckState.Checked Then
            Debug.Print("CheckBox4_CheckedChanged checked!!")

        Else
            Debug.Print("CheckBox4_CheckedChanged unchecked!!")

        End If
    End Sub
End Class
