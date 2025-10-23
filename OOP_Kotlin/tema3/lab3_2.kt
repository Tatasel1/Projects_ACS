import kotlin.random.Random
import java.util.Calendar

class Student(){

    private var nume: String=""
    private   var prenume: String=""
    private   var CNP:String=""
    private  var anNastere: Int=0
    private  var numeFac:String=""
    private   var anInfiintare:Int=0

    fun genCNP(){
        var cnp= String()

        var cif:Int=0
        if(anNastere>=2000){
            cif=Random.nextInt(5,6)
            cnp+=cif.toString()
        }
        else {
            cif=Random.nextInt(1,2)
            cnp+=cif.toString()
        }

        var aa=anNastere%100
        if(aa<10) cnp+='0'
        cnp+=aa.toString()

        var luna=Random.nextInt(1,13)
        var zi =Random.nextInt(1,29)

        if(luna<10) cnp+='0'
        cnp+=luna.toString()

        if(zi<10) cnp+='0'
        cnp+=zi.toString()

        for (i in 1..6){
         var c=Random.nextInt(1,9)
         cnp+=c.toString()
        }

        val control="279146358279"

        var s=0

        for (i in 0..11){
            s+=cnp[i].digitToInt()*control[i].digitToInt()

        }
        var rest=s%11

        var cifCtrl=0
        if(rest<10)
            cifCtrl=rest
        else cifCtrl=1


        cnp+=cifCtrl.toString()


        this.CNP=cnp
    }


    fun setNume(nume:String){
        this.nume=nume
    }
    fun setPrenume(prenume:String){
        this.prenume=prenume
    }
    fun setCNP(cnp:String){
        this.CNP=cnp
    }
    fun setAnNastere(anNastere:Int){
        this.anNastere=anNastere
    }
    fun setAnInfiintare(anInfiintare:Int){
        this.anInfiintare=anInfiintare
    }
    fun setNumeFac(numeFac:String){
        this.numeFac=numeFac
    }


    fun getNume():String{
        return this.nume
    }
    fun getPrenume():String{
        return this.prenume
    }
    fun getCNP():String{
        return this.CNP
    }
    fun getAnNastere():Int{
        return this.anNastere
    }
    fun getNumeFac():String{
        return this.numeFac
    }
    fun getAnInfiintare():Int{
        return this.anInfiintare
    }


    fun getSex(cnp: String):String{
        val s=cnp[0]
        if(s=='5' || s=='1')
            return "Masculin"
        else return "Feminin"
    }

    fun getVarsta(): Int{
        val calendar=Calendar.getInstance()
        var year=calendar.get(Calendar.YEAR)

        return year-anNastere
    }

    fun Diff():Int{
        return anInfiintare-anNastere
    }

    fun print(){
        println("Numele: ${getNume()} ${getPrenume()} \n")
        println("Anul nasterii: ${getAnNastere()} \n")
        println("Varsta: ${getVarsta()} \n")
        println("Facultatea: ${getNumeFac()}  (${getAnInfiintare()})\n")

    }

}

fun main() {
    val student1 = Student()
    student1.genCNP()
    student1.setNume("Popescu")
    student1.setPrenume("Matei")
    student1.setAnNastere(2004)
    student1.setNumeFac("UPB")
    student1.setAnInfiintare(1800)

    student1.print()
    println(student1.getSex(student1.getCNP()))
}