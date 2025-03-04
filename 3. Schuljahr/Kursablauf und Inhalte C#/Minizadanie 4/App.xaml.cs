namespace Minizadanie_4_2;

public partial class App : Application
{
	public App()
	{
		InitializeComponent();

        var navPage = new NavigationPage(new MainPage());
        navPage.BarBackground = Colors.Pink;
        navPage.BarTextColor = Colors.White;
       MainPage = new TabbedPageDemo();            

       //  MainPage = new FlyoutPageDemo();      //menim v kroku 46

//       MainPage = navPage;     // menim v kroku 40


    }
}
