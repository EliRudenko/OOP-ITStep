namespace UniversityMVC.Models
{
    public class SubjectsGroups
    {
        public int Id { get; set; }
        public int SubjectId { get; set; }
        public int GroupId { get; set; }
        public int TeacherId { get; set; } 

        public Subject Subject { get; set; } = null!;
        public Group Group { get; set; } = null!;
        public Teacher Teacher { get; set; } = null!;  
    }
}
