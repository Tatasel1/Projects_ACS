open class CEO{
    open fun salary(){
        println("10M per year")
    }
    open fun name(){
        println("Jeff Bezos")
    }
}


open class Manager: CEO(){
    open override fun salary(){
        println("Could buy a Porsche, but drives a Prius instead (around 100k a year)")
    }
    open override fun name(){
        println("Mark Henry")
    }
}

class Developer: Manager(){
    override fun salary(){
        println("Loans a Porsche to drive around, lying to himself he will buy it someday (around 60k a year)")
    }

    override fun name(){
        println("Matt")
    }
}

fun main(){
    val ceo=CEO();
    ceo.salary()
    ceo.name()

    val manager=Manager()
    manager.salary()
    manager.name()

    val developer=Developer()
    developer.salary()
    developer.name()
}