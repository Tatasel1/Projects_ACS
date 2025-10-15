class Motorbike(val topSpeed: Double, val name:String, val model:String,val cubicCapacity:Int){

    constructor(name:String,model:String):this(350.99,name,model,1099){
        println("$topSpeed | $name | $model | $cubicCapacity ")

    }

    fun printObj(){
        println("$topSpeed | $name | $model | $cubicCapacity ")
    }

}

fun main(){
    val motor1=Motorbike(400.67,"Honda","1000RR",1000)
    val motor2=Motorbike(387.98,"Hayabusa","1000RR",1340)
    motor1.printObj()
    motor2.printObj()

    val motor3=Motorbike("Kawasaki ","Ninja")
    val motor4=Motorbike("Ducatti","Superleggera")

}