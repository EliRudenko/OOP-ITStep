using System.ComponentModel.DataAnnotations;

namespace UniversityMVC.Models
{
    public class Subject
    {
        public int Id { get; set; }

        [RegularExpression("^[a-z ,.'-]+$", ErrorMessage = "Regex name error")]
        public string Name { get; set; }
        public ICollection<Group> Groups { get; set; } = null!;

        public ICollection<SubjectsGroups> SubjectsGroups { get; set; } = null!;
    }
}
