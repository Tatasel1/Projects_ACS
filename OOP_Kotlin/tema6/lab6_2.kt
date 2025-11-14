/*
In Kotlin nu exista friend classes, insa variabilele declarate de tip val sau var daca sunt publice, se poate lucra in clasele derivate la fel ca intr-un friend class
Alta varianta nu am gasit de a inlocui friend
 */

/*
Am creat o interfata carte apoi trei clase derivate pentru a putea lucra cu variabilele din codul C++
in interfete toate functiile sunt abstracte
*/

interface Carte {
    var titlu: String
    var autor: String
    var anPublicare: Int
    var disp: Boolean

    fun afiseazaInfo()
    fun verifDisp()
}

class CarteTiparita(
    override var titlu: String = "",
    override var autor: String = "",
    override var anPublicare: Int = 0,
    override var disp: Boolean = true
) : Carte {
    override fun afiseazaInfo() {
        println("Titlu: $titlu")
        println("Autor: $autor")
        println("An Publicare: $anPublicare")
        println("Disponibilitate: ${if (disp) "Disponibila" else "Indisponibila"}")
    }

    override fun verifDisp() {
        println("Cartea $titlu este ${if (disp) "disponibila" else "indisponibila"}.")
    }
}

class CarteElectronica(
    override var titlu: String = "",
    override var autor: String = "",
    override var anPublicare: Int = 0,
    override var disp: Boolean = true,
    private var dimensiuneMB: Float = 0.0f
) : Carte {

    override fun afiseazaInfo() {
        println("Titlu: $titlu")
        println("Autor: $autor")
        println("An Publicare: $anPublicare")
        println("Disponibilitate: ${if (disp) "Disponibila" else "Indisponibila"}")
        println("Dimensiune (MB): $dimensiuneMB")
    }

    override fun verifDisp() {
        println("Cartea electronica $titlu este ${if (disp) "disponibila pentru descarcare" else "indisponibila"}.")
    }
}

class Biblioteca {
    fun modifAutor(c: Carte, a: String) {
        if (c.autor != a) {
            c.autor = a
            println("Autorul a fost modificat!")
        } else {
            println("Autorul este acelasi!")
        }
    }

    /*
    Am folosit companion object deoarece in codul C++ functiile urmatoare sunt statice
    Totodata, am vrut sa afisez informatiile cartilor fizice direct din clasa biblioteca, pentru asta sunt verifDispo si afiseazaInformatii
    Totusi, inca am nevoie de metode in clasa carteTiparita deoarece trebuie sa faca override la toate metodele din interfata Carte
    */

companion object {
        fun verifDispo(c: Carte) {
            println("Cartea ${c.titlu} este ${if (c.disp) "disponibila" else "indisponibila"}.")
        }

        fun afiseazaInformatii(c: Carte) {
            println("Titlu: ${c.titlu}")
            println("Autor: ${c.autor}")
            println("An Publicare: ${c.anPublicare}")
            println("Disponibilitate: ${if (c.disp) "Disponibila" else "Indisponibila"}")
        }
    }
}

fun modifTitlu(c: Carte, t: String) {
    if (c.titlu != t) {
        c.titlu = t
        println("Titlul cartii a fost modificat in $t")
    } else {
        println("Titlul este acelasi!")
    }
}

fun main() {
    val c1: Carte = CarteTiparita("Ion", "Liviu Rebreanu", 1920, true)
    val c2: Carte = CarteTiparita("Morometii", "Marin Preda", 1955, false)
    val ce1: Carte = CarteElectronica("1984", "George Orwell", 1949, true, 1.5f)

    val b = Biblioteca()

    Biblioteca.verifDispo(c1)
    Biblioteca.afiseazaInformatii(c1)
    println()

    modifTitlu(c1, "Ional")
    Biblioteca.verifDispo(c1)
    Biblioteca.afiseazaInformatii(c1)
    println()

    b.modifAutor(c2, "Marin Predut")
    Biblioteca.verifDispo(c2)
    Biblioteca.afiseazaInformatii(c2)
    println()

    ce1.verifDisp()
    ce1.afiseazaInfo()
}

