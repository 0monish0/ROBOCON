// # types of gates AND OR XOR  implementation through slide switch
int p1, p2;
char Gt = ' ';

void setup() {
    pinMode(13, INPUT);
    pinMode(12, INPUT);
    pinMode(11, OUTPUT);
    Serial.begin(9600);
    Serial.println("Enter A for AND, O for OR, X for XOR");
}

void loop() {
    if (Serial.available() > 0) {
        Gt = Serial.read();
        Serial.print("Gate: ");
        Serial.println(Gt);
    }

    p1 = digitalRead(13);
    p2 = digitalRead(12);

    int out = 0;

    switch (Gt) {
        case 'A':
        case 'a':
            out = (p1 && p2) ? HIGH : LOW;
            break;
        case 'O':
        case 'o':
            out = (p1 || p2) ? HIGH : LOW;
            break;
        case 'X':
        case 'x':
            out = (p1 != p2) ? HIGH : LOW;
            break;
        default:
            out = LOW;
            break;
    }

    digitalWrite(11, out);
    delay(100);
}
