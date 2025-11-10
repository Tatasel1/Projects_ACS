open class CEO(
    open val nume: String = "Jeff Bezos",
    open val salariu: Double = 10.0
) {
    open fun salary() {
        kotlin.io.println("${salariu}M per year")
    }

    open fun name() {
        kotlin.io.println(nume)
    }
}

open class Manager(
    override val nume: String = "Mark Henry",
    override val salariu: Double = 100.0
) : CEO(nume, salariu) {
    override fun salary() {
        kotlin.io.println("Could buy a Porsche, but drives a Prius instead (around ${salariu}k a year)")
    }
}

class Developer(
    override val nume: String = "Matt",
    override val salariu: Double = 50.0
) : Manager(nume, salariu) {
    override fun salary() {
        kotlin.io.println("Loans a Porsche to drive around, lying to himself he will buy it someday (around ${salariu}k a year)")
    }
}

fun main(){
    val ceo=CEO();
    ceo.name()
    ceo.salary()


    val manager=Manager()
    manager.name()
    manager.salary()


    val developer=Developer()
    developer.name()
    developer.salary()

}