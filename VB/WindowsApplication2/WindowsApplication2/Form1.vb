Imports System.IO
Imports System.Threading

Public Class Form1

    Dim dpSize As Integer = 60
    Dim dpX() As Single = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                           11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                           21, 22, 23, 24, 25, 26, 27, 28, 29, 30,
                           31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
                           41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
                           51, 52, 53, 54, 55, 56, 57, 58, 59, 60}
    Dim dpY() As Single = {67, 66, 68, 69, 70, 67, 66, 69, 72, 77,
                           80, 77, 77, 80, 77, 81, 84, 81, 77, 77,
                           80, 77, 77, 80, 77, 81, 84, 81, 77, 77,
                           80, 77, 77, 80, 77, 81, 84, 81, 77, 77,
                           80, 77, 77, 80, 77, 81, 84, 81, 77, 77,
                           76, 75, 74, 73, 73, 74, 73, 72, 71, 70}
    Dim dpRaw() As Single = {0, 26, 58, 69, 80, 67, 58, 29, 12, 3,
                           0, 26, 58, 69, 80, 67, 58, 29, 12, 3,
                           0, 26, 58, 69, 80, 67, 58, 29, 12, 3,
                           0, 26, 58, 69, 80, 67, 58, 29, 12, 3,
                           0, 26, 58, 69, 80, 67, 58, 29, 12, 3,
                           0, 26, 58, 69, 80, 67, 58, 29, 12, 3}

    Public datapointThread As System.Threading.Thread

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        ListBox1.Items.Add(":Button1 " + "clicked")

        'public System.Windows.Forms.OpenFileDialog ofdOpen = new System.Windows.Forms.OpenFileDialog();
        Dim ofdOpen As New OpenFileDialog()
        Dim ofdStream As Stream = Nothing
        'Dim rows As New ArrayList
        'Dim bytes(50) As Byte

        ofdOpen.Filter = "csv files (*.csv) | text files (*.txt) | All files (*.*) | *.*"
        ofdOpen.FilterIndex = 2
        ofdOpen.RestoreDirectory = True

        If ofdOpen.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
            Try
                ofdStream = ofdOpen.OpenFile()
                If (ofdStream IsNot Nothing) Then
                    'insert code to read the stream here.
                    ListBox1.Items.Add(":Button1 " + "read file name: " + ofdOpen.FileName)

                    'LoadCsvStream(ofdStream)
                    'LoadCsvParser(ofdOpen.FileName)
                    LoadCsvText(ofdOpen.FileName)
                End If
            Catch ex As Exception
                MessageBox.Show("Cannot read files from disk Original error: " & ex.Message)
            Finally
                'check again
                If (ofdStream IsNot Nothing) Then
                    ofdStream.Close()
                End If
            End Try
        End If
    End Sub

    Private Sub LoadCsvStream(ByVal ofdStream As Stream)
        Dim bytes(50) As Byte

        ofdStream.Read(bytes, 0, 50)
        Dim myloop As Integer
        While (myloop < 50)
            ListBox1.Items.Add(":Button1 " + "read file: " + bytes(myloop).ToString)
            myloop = myloop + 2
        End While
    End Sub

    Private Sub LoadCsvParser(ByVal ofdFileName As String)
        Dim rows As New ArrayList
        'Dim input = My.Computer.FileSystem.OpenTextFieldParser(ofdOpen.FileName)
        Dim input = My.Computer.FileSystem.OpenTextFieldParser(ofdFileName)

        input.SetDelimiters(",")

        While (Not input.EndOfData)
            rows.Add(input.ReadFields)
        End While
        'rows.Add(input.ReadFields)

        ListBox1.Items.Add(":Button1 " + "reader file: " + rows.Item(0)(0).ToString)
        ListBox1.Items.Add(":Button1 " + "reader file: " + rows.Item(0)(1).ToString)
        ListBox1.Items.Add(":Button1 " + "reader file: " + rows(0)(2).ToString)
        ListBox1.Items.Add(":Button1 " + "reader file: " + rows(0)(3).ToString)
        ListBox1.Items.Add(":Button1 " + "reader file: " + rows(0)(4).ToString)
    End Sub

    Private Sub LoadCsvText(ByVal ofdFileName As String)

        Dim wholeFile As String
        Dim wholeBinary(50) As Byte
        Dim lineData() As String
        Dim fieldData() As String

        'Dim filePath As String = ofdOpen.FileName
        Dim filePath As String = ofdFileName
        wholeFile = My.Computer.FileSystem.ReadAllText(filePath)
        wholeBinary = My.Computer.FileSystem.ReadAllBytes(filePath)

        Debug.Print(wholeFile)
        Debug.Print(wholeBinary(0))
        Debug.Print(wholeBinary(1))
        Debug.Print(wholeBinary(2))

        lineData = Split(wholeFile, vbNewLine)
        For Each lineOfText As String In lineData
            fieldData = lineOfText.Split(",")
            For Each wordOfText As String In fieldData
                ListBox1.Items.Add(":Button1 " + "read file: " + wordOfText)
                Debug.Print(wordOfText)
            Next wordOfText
        Next lineOfText

    End Sub

    Private Sub PictureBox1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs)

    End Sub

    Private Sub Form1_FormClosing(ByVal sender As Object, ByVal e As System.Windows.Forms.FormClosingEventArgs) Handles Me.FormClosing
        Debug.Print("Form1_FormClosing")
        datapointThread.Abort()
        Timer1.Stop()
    End Sub

    Private Sub Form1_Load1(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Debug.Print("Form_Load")
        spDrawChartSetup()
    End Sub

    Private Sub spDrawCurvePoint(ByVal e As PaintEventArgs)
        Debug.Print("DrawCurvePoint")

        Dim curvePoints As Point() = {
            New Point(50, 350),
            New Point(60, 360),
            New Point(70, 350),
            New Point(80, 360),
            New Point(90, 350),
            New Point(100, 340),
            New Point(110, 330),
            New Point(120, 330),
            New Point(130, 325),
            New Point(140, 320),
            New Point(150, 315),
            New Point(160, 310),
            New Point(170, 305)
        }

        Dim redPen As New Pen(Color.Red, 4)
        Dim greenPen As New Pen(Color.Green, 3)

        e.Graphics.DrawLines(redPen, curvePoints)
        e.Graphics.DrawCurve(greenPen, curvePoints)

    End Sub

    Private Sub spDrawAxisPoint(ByVal e As System.Windows.Forms.PaintEventArgs, ByVal sX As Integer, ByVal sY As Integer, ByVal sW As Integer, ByVal sH As Integer)
        Debug.Print("Draw_Axis")

        LineShape1.X1 = sX
        LineShape1.Y1 = sY
        LineShape1.X2 = sX
        LineShape1.Y2 = sY + sH
        LineShape1.BorderWidth = 2
        LineShape1.Update()

        LineShape2.X1 = sX
        LineShape2.Y1 = sY + sH
        LineShape2.X2 = sX + sW
        LineShape2.Y2 = sY + sH
        LineShape2.BorderWidth = 2
        LineShape2.Update()


    End Sub

    Private Sub spDrawChartSetup()

        Dim RD As String = "Raw_Data"
        Chart1.Titles.Add("Heart Rate")
        Chart1.Series.Add(RD)
        'Chart1.Series("Series1").ChartType = DataVisualization.Charting.SeriesChartType.Column
        'Chart1.Series("Series1").ChartType = DataVisualization.Charting.SeriesChartType.Line
        'Chart1.Series("Series1").ChartType = DataVisualization.Charting.SeriesChartType.Point
        Chart1.Series(RD).ChartType = DataVisualization.Charting.SeriesChartType.FastLine
        Chart1.Series(RD).ChartArea = "ChartArea1"
        'Chart1.Series(RD").Points.DataBindXY(dpX, dpRaw)

        Dim HR As String = "HeartRate"
        Chart1.Series.Add(HR)
        'Chart1.Series(HR).ChartType = DataVisualization.Charting.SeriesChartType.StepLine
        'Chart1.Series(HR).ChartType = DataVisualization.Charting.SeriesChartType.Line
        'Chart1.Series(HR).ChartType = DataVisualization.Charting.SeriesChartType.Column
        Chart1.Series(HR).ChartType = DataVisualization.Charting.SeriesChartType.Point
        Chart1.Series(HR).Color = Color.Red
        'Chart1.Series("HeartRate").ChartArea = 

        'Chart1.ChartAreas.Add("ChartArea2")
        Chart1.Series(HR).ChartArea = "ChartArea1"
        'Chart1.Series(HR).ChartArea = "ChartArea2"
        'Chart1.Series(HR).Points.DataBindXY(dpX, dpY)

    End Sub

    Private Sub spDrawChart()

        'Chart1.Series("Series1").Points.AddXY(1, 2)
        'Chart1.Series("Series1").Points.AddXY(2, 3)
        'Chart1.Series("Series1").Points.AddXY(3, 1)
        'Chart1.Series("Series1").Points.AddXY(4, 4)
        'Chart1.Series("Series1").Points.AddXY(5, 3)
        'Chart1.Series("Series1").Points.AddXY(6, 1)
        'Chart1.Series("Series1").Points.AddXY(7, 2)
        'Chart1.Series("Series1").Points.AddXY(8, 3)
        'Chart1.Series("Series1").Points.AddXY(9, 1)
        'Chart1.Series("Series1").Points.AddXY(10, 4)
        'Chart1.Series("Series1").Points.AddXY(11, 3)
        'Chart1.Series("Series1").Points.AddXY(12, 1)
        'Chart1.Series("Series1").Points.AddXY(13, 2)
        'Chart1.Series("Series1").Points.AddXY(14, 3)
        'Chart1.Series("Series1").Points.AddXY(15, 1)
        'Chart1.Series("Series1").Points.AddXY(16, 4)
        'Chart1.Series("Series1").Points.AddXY(17, 3)
        'Chart1.Series("Series1").Points.AddXY(18, 1)

        'Dim HR As String = "HeartRate"
        'Dim dpX() As Single = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30}
        'Dim dpY() As Single = {67, 66, 68, 69, 70, 67, 66, 69, 72, 77, 80, 77, 77, 80, 77, 81, 84, 81, 77, 77, 76, 75, 74, 73, 73, 74, 73, 72, 71, 70}
        'For ii = 0 To 29
        'Chart1.Series(HR).Points.AddXY(dpX(ii), dpY(ii))
        'Next
        'Chart1.Series(HR).Points.DataBindXY(dpX, dpY)

    End Sub

    Private Sub Form1_Paint(ByVal sender As Object, ByVal e As System.Windows.Forms.PaintEventArgs) Handles Me.Paint
        Debug.Print("Form1_Paint")

        spDrawAxisPoint(e, 10, 252, 221, 117)
        spDrawCurvePoint(e)

        'Dim blueBrush As New Drawing.SolidBrush(Color.Blue)
        'e.Graphics.FillRectangle(blueBrush, 20, 260, 100, 100)

        spDrawChart()

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Me.Refresh()
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        Me.datapointThread = New System.Threading.Thread(AddressOf Me.datapointThreadSub)
        Me.datapointThread.Start()

        Timer1.Interval = 200
        Timer1.Start()

    End Sub

    Private Sub datapointThreadSub()
        Dim tX As Single = 0
        Dim tY As Single = 0
        Dim tR As Single = 0
        Dim tIdx As Integer = dpSize - 1

        Do
            'Debug.Print("datapointThreadSub")
            'tX = dpX(tIdx)
            tY = dpY(tIdx)
            tR = dpRaw(tIdx)

            For i = 0 To (tIdx - 1)
                'Debug.Print("," + (tIdx - i).ToString + "=" + dpX(tIdx - i).ToString)
                'Debug.Print("," + (tIdx - i).ToString + "=" + dpY(tIdx - i).ToString)
                'dpX(tIdx - i) = dpX(tIdx - i - 1)
                dpY(tIdx - i) = dpY(tIdx - i - 1)
                dpRaw(tIdx - i) = dpRaw(tIdx - i - 1)
            Next
            'dpX(0) = tX
            dpY(0) = tY
            dpRaw(0) = tR
            'Chart1.Update()
            Thread.Sleep(200)
        Loop
    End Sub

    Private Sub Timer1_Tick(ByVal sender As Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        'Debug.Print("Timer1_Tick")
        Chart1.Series("Raw_Data").Points.DataBindXY(dpX, dpRaw)

        'Chart1.Series("HeartRate").Points.ResumeUpdates()
        Chart1.Series("HeartRate").Points.DataBindXY(dpX, dpY)

        'Dim HR As String = "HeartRate"

        'For ii = 0 To (dpSize - 1)
        'Chart1.Series(HR).Points.AddXY(dpX(ii), dpY(ii))
        'Next
    End Sub
End Class
