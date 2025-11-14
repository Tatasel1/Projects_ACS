abstract class City(var street:String="", var population: Int = 0) {
    val attractions: MutableList<String> = mutableListOf()

    abstract fun getStreet()
    abstract fun getAttraction()
    abstract fun getNrAttractions()
    abstract fun getPopulation()


}

class Bucharest(street: String ="B-dul Iuliu Maniu",population: Int = 1716961): City(street,population){

    /*
        Aici am folosit init, am vazut pe ChatGPT si pe net, este folosit pentru ca insturctiunile din interiorul lui sa ruleze odata cu executarea constructorului primar
     */

    init{
        attractions.add("Piata Constitutiei")
        attractions.add("Car-Meet Maniu")
    }

    override fun getStreet(){
        println("An important street: ${street}")
    }

    override fun getNrAttractions(){
        if(attractions.size>0){
            println("There are some attractions in this city")
        }
        else println("There are no attractions in this city")
    }

    override fun getAttraction() {
        if(attractions.size>0) {
            println("Displaying attractions:")
            attractions.forEach { println(it) }
        }
    }

    override fun getPopulation(){
        println("Population: ${population}")
    }

}

class Mumbai(street:String = "Marine Drive", population: Int = 21700000): City(street,population){

    override fun getStreet(){
        println("An important street: ${street}")
    }

    override fun getNrAttractions(){
        if(attractions.size>0){
            println("There are some attractions in this city")
        }
        else println("There are no attractions in this city")
    }
    override fun getAttraction() {
        if(attractions.size>0){
            println("Displaying attractions:")
            attractions.forEach {println(it)}
        }
    }

    override fun getPopulation(){
        println("Population: ${population}")
    }
}

class Rio(street: String = "Rio Ave", population: Int = 6700000): City(street,population){

    init {
        attractions.add("Copacabana Beach")
        attractions.add("Jesus Christ Statue")
        attractions.add("Carnival de Rio")
    }

    override fun getStreet(){
        println("An important street: ${street}")
    }

    override fun getNrAttractions(){
        if(attractions.size>0){
            println("There are some attractions in this city")
        }
        else println("There are no attractions in this city")
    }

    override fun getAttraction() {
        if(attractions.size>0){
            println("Displaying attractions:")
            attractions.forEach {println(it)}
        }
    }

    override fun getPopulation(){
        println("Population: ${population}")
    }

}

fun main(){
    val b=Bucharest()
    val m=Mumbai()
    val r=Rio()

    b.getStreet()
    b.getNrAttractions()
    b.getAttraction()
    b.getPopulation()

    println()

    m.getStreet()
    m.getNrAttractions()
    m.getAttraction()
    m.getPopulation()

    println()

    r.getStreet()
    r.getNrAttractions()
    r.getAttraction()
    r.getPopulation()

}