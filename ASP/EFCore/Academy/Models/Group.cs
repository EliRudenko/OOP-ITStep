using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Group
    {
        public int Id { get; set; }

        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string Name { get; set; }
        public int Year { get; set; }
        public int DepartmentId {  get; set; }
        public Department Department { get; set; } = null!;
        public ICollection<Curator> Curators { get; set; } = null!;
        public ICollection<Lecture> Lectures { get; set; } = null!;

    }
}
