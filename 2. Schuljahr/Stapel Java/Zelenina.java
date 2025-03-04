public class Zelenina {
    String druh;
    String krajinaPovodu;

    Zelenina(String druh, String krajinaPovodu) {
        this.druh = druh;
        this.krajinaPovodu = krajinaPovodu;
    }

    @Override
    public String toString() {
        return this.druh + " from: " + this.krajinaPovodu;
    }

}
