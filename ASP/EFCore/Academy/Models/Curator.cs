using System.ComponentModel.DataAnnotations;

namespace Models
{
    public class Curator
    {
        public int Id { get; set; }

        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string Name { get; set; }

        [RegularExpression(@"^(?!\s*$).+", ErrorMessage = "Name cannot be empty or whitespace.")]
        public string Surname {  get; set; }

        public ICollection<Group> Groups { get; set; } = null!;

    }
}
