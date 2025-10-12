class Student(var nume: String, var prenume: String, var grupa: String) {
    val placut: String =
        "La laboratorul de PA mi-a placut intreaga desfasurare. As dori sa fie pastrat in special felul in care se bazeaza pe intrebari de interviu"
    val neplacut: String =
        "La lab-ul de PA nu au fost lucruri care sa imi displaca in mod special,dar temele ar putea fi pana duminica"
    val amFacutVara: String =
        "Vara aceasta am incercat sa ma explorez pe mine insumi si sa imi dau seama de ce vreau sa fac cu adevarat."
    val vreauSaFac: String =
        "Dupa ce termin facultatea, as dori sa imi dau foc la laptop-ul de acum si sa imi iau un MacBook, sa ma angajez,evident si sa incep sa calatoresc in Europa pentru inceput"
}

fun main(){
    val Tatasel=Student("Tatasel","Daniel","322AC")
    println(" ${Tatasel.nume} ${Tatasel.prenume} \n ${Tatasel.grupa} \n ${Tatasel.placut} \n ${Tatasel.neplacut} \n ${Tatasel.amFacutVara} \n ${Tatasel.vreauSaFac}")
}