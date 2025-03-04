namespace MauiApp3;

public partial class MainPage : ContentPage
{
    //int count = 0;

    public MainPage()
    {
        InitializeComponent();
    }

    private void play_Clicked(object sender, EventArgs e)
    {
        mediaElement.Play();
        	if (mediaElement.CurrentState == CommunityToolkit.Maui.Core.Primitives.MediaElementState.Playing)
                mediaElement.Pause();
            
            else if (mediaElement.CurrentState == CommunityToolkit.Maui.Core.Primitives.MediaElementState.Paused)
                mediaElement.Play();
    }

    private void pause_Clicked(object sender, EventArgs e)
    {
        mediaElement.Pause();
    }

    private void stop_Clicked(object sender, EventArgs e)
    {
        mediaElement.Stop();
    }
}

