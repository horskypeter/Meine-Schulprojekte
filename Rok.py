def je_priestupny(rok):
    return (rok % 4 == 0 and rok % 100 != 0) or (rok % 400 == 0)

while True:
    try:
        rok = int(input("Zadajte rok (alebo zadajte niečo iné na ukončenie): "))
    except ValueError:
        print("Neplatný vstup. Ukončujem program.")
        break  # Ukončiť cyklus v prípade neplatného vstupu

    if je_priestupny(rok):
        print(f"{rok} je priestupný rok.")
    else:
        print(f"{rok} nie je priestupný rok.")
