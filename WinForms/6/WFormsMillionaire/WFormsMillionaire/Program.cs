namespace WFormsMillionaire
{
    internal static class Program
    {
        /// <summary>
        ///  The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main()
        {
            // To customize application configuration such as set high DPI settings or default font,
            // see https://aka.ms/applicationconfiguration.
            ApplicationConfiguration.Initialize();
            Form1 form1 = new();
            Model model = new();
            Presenter presenter = new(form1,model);
            Application.Run(form1);
        }
    }
}