class ContBancar {
    var titularCont: String = ""
        get() {
            return field
        }

    var sold: Double = 0.0
        get() {
            return field
        }

    constructor(titularCont: String, sold: Double) {
        this.titularCont = titularCont
        this.sold = sold
    }

    fun depune(suma: Double) {
        this.sold += suma

    }

    fun retrage(suma: Double) {
        if (suma < this.sold) {
            this.sold -= suma
            println("S-a retras suma ${sold} RON \n")

        } else println("Fonduri insuficiente\n")

    }

    ///Am vazut ca in loc de static,in kotlin pot folosi companion object,care se comporta aproape la fel


    companion object {
        private var rataDobanda: Double = 0.0

        public fun seteazaRataDobanda(rataNoua: Double) {
            rataDobanda = rataNoua
        }
    }

    fun aplicaDobanda(){
        var d:Double=rataDobanda*this.sold
        this.sold+=d
    }

    fun printCont(){
        println("${titularCont}  ${sold}\n")
    }

}


fun main(){

    val cont1=ContBancar("Andreescu Mihai",13600.2341)
    val cont2=ContBancar("Dinca Angela",23.456)

    cont1.depune(1230.234);
    cont2.depune(10.123);
    cont1.retrage(1230.234);
    cont2.retrage(1230.234);

    var s1=cont1.sold
    var s2=cont2.sold

    println("Sold cont 1: ${s1}"+ "Sold cont 2 ${s2}")

    ContBancar.seteazaRataDobanda(0.07)

    cont1.aplicaDobanda()
    cont2.aplicaDobanda()
    cont1.printCont()
    cont2.printCont()


}
