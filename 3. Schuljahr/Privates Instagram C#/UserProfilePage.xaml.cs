using Microsoft.Maui.Controls;

namespace Zadanie_3
{
    public partial class UserProfilePage : ContentPage
    {
        public UserProfilePage(User user)
        {
            InitializeComponent();

            // Nastavujem zobrazované informácie o používateľovi
            UserID.Text = $"UserID: {user.UserID}";
            Description.Text = user.Description;
            imgUser.Source = user.ImageUrl;
        }
    }
}
