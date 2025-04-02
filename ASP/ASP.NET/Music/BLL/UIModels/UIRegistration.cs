using System.ComponentModel.DataAnnotations;

namespace BLL.UIModels
{
    public class UIRegistration
    {
        [Required]
        [Length(6, 20)]
        [RegularExpression("^[a-zA-Z0-9._-]{3,20}$", ErrorMessage = "Incorrect username")]

        public string Username { get; set; } = null!;
        [Required]
        [Length(6, 20)]
        [DataType(DataType.Password)]
        [RegularExpression(@"^(?=\S*?[A-Z])(?=\S*?[a-z])(?=\S*?\d).{6,}$",
            ErrorMessage = "Password must be at least 6 characters long and contain at least one uppercase letter, one lowercase letter, and one digit. No spaces allowed.")]
        public string Password { get; set; } = null!;
        [Required]
        [Compare(nameof(Password), ErrorMessage = "Passwords do not match")]
        [DataType(DataType.Password)]
        public string ConfirmPassword { get; set; } = null!;
    }
}
