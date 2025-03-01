namespace IT_Employee_WinForms
{
    public class Logger
    {
        static readonly string filePath = "log.txt";

        public static void Log(string message)
        {
            using (StreamWriter sw = new StreamWriter(filePath,true))
            {
                sw.WriteLine(message + ' ' + (DateTime.Now));
            }
        }
    }
}
