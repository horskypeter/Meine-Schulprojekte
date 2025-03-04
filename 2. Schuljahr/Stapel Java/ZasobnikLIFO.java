public class ZasobnikLIFO {
    Object stack[];
    int top;
    int len;

    ZasobnikLIFO(int velkost) {
        this.stack = new Object[velkost];
        top = 0;
        len = this.stack.length;
    }

    void push(int cislo) {
        if (top < len) {
            stack[top] = cislo;
            top = top + 1;
        } else {
            System.out.println("Zasobnik je plny");
        }
    }

    void push(String slovo) {
        if (top < len) {
            stack[top] = slovo;
            top = top + 1;
        } else {
            System.out.println("Zasobnik je plny");
        }
    }
        void push(char znak) {
            if (top < len) {
                stack[top] = znak;
                top = top + 1;
            } else {
                System.out.println("Zasobnik je plny");
            }
        }
void push(Zelenina zelenina )
{
    if (top < len) {
        stack[top] = zelenina;
        top = top + 1;
    } else {
        System.out.println("Zasobnik je plny");
    }
}

    Object pop() {
        if (top > 0) {
            top = top - 1;
            return stack[top];
        } else {
            System.out.println("Zasobnik je prazdny");
            return -1;
        }
    }
    void print(){
        for(int i = top-1;i>-1;i--){
            System.out.print("["+ stack[i]+"] ");
        }
    }
}

