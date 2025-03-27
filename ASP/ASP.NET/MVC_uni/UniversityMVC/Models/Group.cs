using System.ComponentModel.DataAnnotations;

namespace UniversityMVC.Models
{
    public class Group
    {
        public int Id { get; set; }

        [RegularExpression("^[a-z0-9 ,.'-]+$", ErrorMessage = "Regex name error")]
        public string Name { get; set; }

        public ICollection<Subject> Subjects { get; set; } = null!;
        public ICollection<Student> Students { get; set; } = null!;
        public ICollection<SubjectsGroups> SubjectsGroups { get; set; } = null!;



    }
}
