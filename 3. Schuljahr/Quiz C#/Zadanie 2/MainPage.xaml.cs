namespace Zadanie_2;

public partial class MainPage : ContentPage
{
    private List<Zaznam> zoznam;
    private int aktualny_index = 0;
    private int pocet_spravnych = 0;
    private int pocet_odpovedi = 0;

    public MainPage()
    {
        InitializeComponent();

        bool ak_existuje = File.Exists(@"C:\users\horsk\onedrive\počítač\zadania gui\zadanie 2\textfile1.txt");     // overenie ci subor existuje

        if (ak_existuje == true)
        {
            zoznam = new List<Zaznam>();                                                                            // vytvaram zoznam
            string cesta = @"C:\users\horsk\onedrive\počítač\zadania gui\zadanie 2\textfile1.txt";

            if (File.Exists(cesta))
            {
                string[] riadky = File.ReadAllLines(cesta);                                                         // nacitavam po riadkoch

                for (int i = 0; i < riadky.Length; i += 6)
                {
                    string otazka = riadky[i];
                    string moznostA = riadky[i + 1];
                    string moznostB = riadky[i + 2];
                    string moznostC = riadky[i + 3];
                    string moznostD = riadky[i + 4];
                    string spravna_odpoved = riadky[i + 5];

                    Zaznam zaznam = new Zaznam(i, otazka, moznostA, moznostB, moznostC, moznostD, spravna_odpoved);
                    zoznam.Add(zaznam);                                                                             // ukladam do zaznamu
                }

                aktualny_index = 0;
                Aktalizuj_otazku();
            }
        }
        else
        {
            DisplayAlert("Chyba", "Soubor neexistuje", "OK");
        }
    }
    private void Button_Clicked(object sender, EventArgs e)                                                         // ak kliknem tak vyhodnoti
    {
        if (aktualny_index < zoznam.Count - 1)
        {
            if (MoznostA.IsChecked && zoznam[aktualny_index].MoznostA == zoznam[aktualny_index].Spravna_odpoved)
            {
                pocet_spravnych++;
            }
            else if (MoznostB.IsChecked && zoznam[aktualny_index].MoznostB == zoznam[aktualny_index].Spravna_odpoved)
            {
                pocet_spravnych++;
            }
            else if (MoznostC.IsChecked && zoznam[aktualny_index].MoznostC == zoznam[aktualny_index].Spravna_odpoved)
            {
                pocet_spravnych++;
            }
            else if (MoznostD.IsChecked && zoznam[aktualny_index].MoznostD == zoznam[aktualny_index].Spravna_odpoved)
            {
                pocet_spravnych++;
            }

            pocet_odpovedi++;
            Vycisti_radio_buttons();
            aktualny_index++;
            Aktalizuj_otazku();                                                                                     // aktualizuje otazku
            Spravne_odpovede.Text = $"Správne odpovede: {pocet_spravnych}";                                         // vypise spravne odpovede
            Vsetky_odpovede.Text = $"Všetky odpovede: {pocet_odpovedi}";                                            // vypise pocet otazok
        }
        else
        {                                                                                                           // posledna otazka    
            if (MoznostA.IsChecked && zoznam[aktualny_index].MoznostA == zoznam[aktualny_index].Spravna_odpoved)
            {
                pocet_spravnych++;
            }
            else if (MoznostB.IsChecked && zoznam[aktualny_index].MoznostB == zoznam[aktualny_index].Spravna_odpoved)
            {
                pocet_spravnych++;
            }
            else if (MoznostC.IsChecked && zoznam[aktualny_index].MoznostC == zoznam[aktualny_index].Spravna_odpoved)
            {
                pocet_spravnych++;
            }
            else if (MoznostD.IsChecked && zoznam[aktualny_index].MoznostD == zoznam[aktualny_index].Spravna_odpoved)
            {
                pocet_spravnych++;
            }
            pocet_odpovedi++;                                                                                       // vypisanie uspesnosti
            DisplayAlert("Výsledok", $"Správne odpovede: {pocet_spravnych} \nVšetky odpovede: {pocet_odpovedi}\nÚspešnosť: {(float)pocet_spravnych / (float)pocet_odpovedi * 100} %", "OK");
        }
    }
    private void Vycisti_radio_buttons()                                                                            // cistim buttons
    {
        MoznostA.IsChecked = false;
        MoznostB.IsChecked = false;
        MoznostC.IsChecked = false;
        MoznostD.IsChecked = false;
    }
    private void Aktalizuj_otazku()                                                                                 // aktualizujem otazku
    {
        Otazka.Text = zoznam[aktualny_index].Otazka;
        MoznostA.Content = zoznam[aktualny_index].MoznostA;
        MoznostB.Content = zoznam[aktualny_index].MoznostB;
        MoznostC.Content = zoznam[aktualny_index].MoznostC;
        MoznostD.Content = zoznam[aktualny_index].MoznostD;
    }
    private void MoznostA_CheckedChanged(object sender, CheckedChangedEventArgs e)
    {

    }
    private void MoznostB_CheckedChanged(object sender, CheckedChangedEventArgs e)
    {

    }
    private void MoznostC_CheckedChanged(object sender, CheckedChangedEventArgs e)
    {

    }
    private void MoznostD_CheckedChanged(object sender, CheckedChangedEventArgs e)
    {

    }
    private void ExitButton_Click(object sender, EventArgs e)                                                       // ukoncenie APP
    {
        Environment.Exit(0);
    }
}