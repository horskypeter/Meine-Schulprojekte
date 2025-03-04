namespace Minizadanie_5_3;

public partial class MainPage : ContentPage
{

    static string[] Field = {
        "Za každým veľkým mužom stojí silná žena. - Benjamin Disraeli",
        "Život je 10% to, čo sa stane s tebou, a 90% to, ako na to reaguješ. - Charles R. Swindoll",
        "Vždy sa zdá nemožné, kým to neurobíš. - Nelson Mandela",
        "Študujte včera, žite dnes, veríme zajtrajšku. - Eleanor Roosevelt",
        "Snažím sa neustále robiť veci, ktoré sa nedajú urobiť. To je spôsob, ako sa ich naučiť robiť. - Pablo Picasso",
        "Ak niečo robíš, rob to tak dobre, že sa bude chcieť vrátiť a zopakovať to znova. - Walt Disney",
        "Nikdy sa nevzdávaj, pretože prehrať sa dá len vtedy, ak sa vzdáš. - Babe Ruth",
        "Ak by som videl ďalej, ako ostatní, je to preto, lebo som stal na pleciach gigantov. - Isaac Newton",
        "Najlepší spôsob, ako predpovedať budúcnosť, je ju vytvoriť. - Peter Drucker"
    };

    public MainPage()
    {
        InitializeComponent();
        mySlider.Value = 33;
        mySlider2.Value = 0.3;
        citat.Text = Field[0];
    }
    private void Slider_ValueChanged(object sender, ValueChangedEventArgs e)
    {

    }
    private void Button_Clicked(object sender, EventArgs e)
    {
        var random = new Random();
        var Index = random.Next(0, Field.Length);
        citat.Text = Field[Index];

        Index++;
        if (Index >= Field.Length)
        {
            Index = 0;
        }
        citat.Text = Field[Index];
    }
}


