using System.ComponentModel.DataAnnotations;


namespace UniversityMVC.Models
{
    public class Student
    {
        public int Id { get; set; }
        [RegularExpression("^[a-z ,.'-]+$", ErrorMessage = "Regex name error")]
        public string Name { get; set; }

        [RegularExpression("^[a-z ,.'-]+$", ErrorMessage = "Regex name error")]
        public string LastName { get; set; }
        [Range(1,4,ErrorMessage ="Course is between 1 and 4")]
        public int Year { get; set; }

        public int GroupId {  get; set; }
        public Group Group { get; set; } = null!;
    }
}
