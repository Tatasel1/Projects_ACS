interface ILogger {
    fun logMessage(msg: String)
}

/*
In tipul de date abstract putem avea si functii concrete
 */

abstract class Dispozitiv(protected val numeDispozitiv: String) {
    fun getNume(): String {
        return numeDispozitiv
    }

    abstract fun esteConectat(): Boolean
}

/*
!!!IMPORTANT
Clasa imprimanta nu face multiple inheritance.Aceasta mosteneste o clasa abstracta si o interfata.
In Kotlin o clasa nu poate mostenii mai multe clase concrete, insa se poate mostenii o clasa si ORICATE interfete.
 */

class Imprimanta(
    nume: String,
    private val conectat: Boolean
) : Dispozitiv(nume), ILogger {

    override fun esteConectat(): Boolean {
        return conectat
    }

    override fun logMessage(msg: String) {
        println("[Imprimanta $numeDispozitiv]: $msg")
    }
}

fun main() {
    val imprimanta1 = Imprimanta("HP LaserJet", true)

    if (imprimanta1.esteConectat()) {
        imprimanta1.logMessage("Imprimanta este conectata si functionala.")
    } else {
        imprimanta1.logMessage("Imprimanta nu este conectata.")
    }

    imprimanta1.logMessage("Incepe imprimarea documentului...")
}
