import kotlin.math.PI

class Volume{

    fun volume(l: Float): Float{
        return l*l*l

    }
    fun volume(r: Float, esteSfera: String ): Float{

        if(esteSfera == "DA")
            return ((r*r*r*PI)*4/3).toFloat()
         else {
             return 0f
         }

    }

    fun volume(Ariab: Float, h: Float): Float{
        return (Ariab*h)/2
    }

    fun volume(){
        println("Introduceti parametrii")
    }
}

fun main(){
    val volume = Volume()
    volume.volume()
    println(volume.volume(12.44f))
    println(volume.volume(10.22f,"DA"))
    println(volume.volume(10.22f, 20.22f))
}