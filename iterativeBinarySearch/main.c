int iterativeBinarySearch(int *v, int n, int target) {
    int first = 0, lenght = n;
    bool found = false;
    while (lenght > 0 && !found) {
        if (v[first + lenght / 2] == target)
            found = true;
        else if (v[first + lenght / 2] < target) { //vado nella parte a destra
            first = (lenght / 2 + 1); //si fa lenght/2 e poi +1 per scartare via l'elemento centrale (sotto esame)
            lenght -= first;
        }
        else { //vado nella parte a sinistra
            lenght /= 2; //l'elemento centrale sotto esame viene già scartato via facendo lenght/2
        }
    }
}

//lenght/2 rappresenta quindi precisamente l'elemento in esame, verra ovviamente escluso per la
//parte sinistra (lenght è sempre nUltimoEl+1) ma per la parte destra no, sarebbe il primo!
//si fa quindi +1 per escluderlo