using System.Collections.Generic;


namespace Zadanie_3
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();

            // Vytvaram zoznamu používateľov
            var userList = new List<User>
            {
                new User { UserID = 1, Description = "Milovník dobrodružstva", ImageUrl = "https://loremflickr.com/100/100/person?lock=1" },
                new User { UserID = 2, Description = "Kreatívna duša", ImageUrl = "https://loremflickr.com/100/100/person?lock=2" },
                new User { UserID = 3, Description = "Vášnivý športovec", ImageUrl = "https://loremflickr.com/100/100/person?lock=3" },
                new User { UserID = 4, Description = "Technológia je moja vášeň", ImageUrl = "https://loremflickr.com/100/100/person?lock=4" },
                new User { UserID = 5, Description = "Milovník kníh", ImageUrl = "https://loremflickr.com/100/100/person?lock=5" },
                new User { UserID = 6, Description = "Veľký bojovník", ImageUrl = "https://loremflickr.com/100/100/person?lock=6" },
                new User { UserID = 7, Description = "Adrenalín mám vo svojej krvy", ImageUrl = "https://loremflickr.com/100/100/person?lock=7" }
            };

            // Nastavenie zoznamu používateľov pre ListView
            userListview.ItemsSource = userList;
        }

        private void OnItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            if (e.SelectedItem is User selectedUser)
            {
                Navigation.PushAsync(new UserProfilePage(selectedUser));
            }
             userListview.SelectedItem = null;
        }
    }

    public class User
    {
        public int UserID { get; set; }
        public string Description { get; set; }
        public string ImageUrl { get; set; }
    }
}

