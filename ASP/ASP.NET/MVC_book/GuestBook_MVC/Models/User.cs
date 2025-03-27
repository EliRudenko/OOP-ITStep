using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace GuestBook_MVC.Models
{
    public class User
    {
        public int Id { get; set; }
        [Required]
        [Length(7,20,ErrorMessage = "Required length is from 7 to 20 symbols")]
        [RegularExpression("^[a-zA-Z0-9._-]{3,20}$",ErrorMessage = "Incorrect username")]
        public string Name { get; set; } = null!;

        [Required]
        [Length(7, 20, ErrorMessage = "Required length is from 7 to 20 symbols")]
        [DataType(DataType.Password)]
        [RegularExpression(@"^(?=\S*?[A-Z])(?=\S*?[a-z])(?=\S*?\d).{6,}$",
            ErrorMessage = "Password must be at least 6 characters long and contain at least one uppercase letter, one lowercase letter, and one digit. No spaces allowed.")]
        public string Password { get; set; } = null!;

        [Display(Name = "Confirm password")]
        [DataType(DataType.Password)]
        [NotMapped]
        public string ConfirmPassword { get; set; }

        public ICollection<Message> Messages { get; set; } = null!;
    }
}
