
/*pentru a prelua data si ora curenta din calculator ne va trebui sa importam o clasa din java ce imi va permite sa manipulez aceste informatii*/

import java.util.Calendar

class Date (var day:Int,
            var month:Int,
            var year: Int,
            var hour:Int) {

    ///this face apel la constructorul primar, ca in exemplu nu stiu de ce nu a mers

    constructor(): this(0,0,0,0){


    val calendar = Calendar.getInstance();

    day = calendar.get(Calendar.DAY_OF_MONTH)
    month = calendar.get(Calendar.MONTH)
    year = calendar.get(Calendar.YEAR)

    hour = calendar.get(Calendar.HOUR_OF_DAY)
        println("Data curenta: $day-$month-$year, Ora: $hour")

        val minute=calendar.get(Calendar.MINUTE)
        val second=calendar.get(Calendar.SECOND)
        var hours_remaining=24-hour

        if(minute > 0 || second > 0) {
            hours_remaining--
        }

        println("Ore ramase: $hours_remaining ")


}



}

fun main(){
    val date = Date()

}