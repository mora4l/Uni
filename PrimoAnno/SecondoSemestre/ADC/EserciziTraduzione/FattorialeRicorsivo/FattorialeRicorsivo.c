int Fattoriale(int numero) // s0
{
    int sottrattomedio=0 //t0
    int f; //t1
    if (numero == 0)
        f = 1;
    else
        sottrattomedio=numero-1
        f = numero * Fattoriale(sottrattomedio);
    return f;
}