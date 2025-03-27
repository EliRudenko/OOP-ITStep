namespace FileHandlerClass
{
    public class FileHandler
    {
        static readonly string path = "users.txt";
        static FileHandler()
        {
            try
            {
                if (!File.Exists(path))
                    File.WriteAllText(path, ""); 
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error creating file: {ex.Message}");
            }
        }
        public static void Write(string text)
        {
            File.WriteAllText(path, text);
        }

        public static string Read()
        {
            return File.ReadAllText(path);
        }

    }
}
