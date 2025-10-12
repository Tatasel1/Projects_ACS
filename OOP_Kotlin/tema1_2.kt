class Sorter{
    fun sortingAlgBubble(arr:MutableList<Int>,n: Int){
        for(i in 0..n){
            for(j in (i+1)..n){
                if(arr[i]<arr[j]){
                    val temp = arr[i]
                    arr[i] = arr[j]
                    arr[j] = temp
                }

            }
        }
    }


    fun sortingAlgInsertion(arr:MutableList<Int>,n: Int){
        for(i in 0..n){
            val temp = arr[i]
            var j=i-1
            while(j>=0 && arr[j]<temp){
                arr[j+1]=arr[j]
                j-=1
            }
            arr[j+1]=temp
        }
    }


    fun sortingAlgSelection(arr:MutableList<Int>,n: Int){
        var p=0
        for(i in 0..n){
            p=i
            var max=arr[i]
            for(j in (i+1)..n){
                if(arr[j]>max){
                    max=arr[j]
                    p=j
                }
            }
            val temp=arr[p]
            arr[p] = arr[i]
            arr[i]=temp
        }
    }


    fun merge(arr:MutableList<Int>,st: Int, mid: Int, dr: Int){
        val nr1=mid-st+1
        val nr2=dr-mid
        val stg=MutableList(nr1) {0}
        val drt=MutableList(nr2) {0}

        for(i in 0..nr1-1)
            stg[i]=arr[st+i]

        for(j in 0..nr2-1){
            drt[j]=arr[mid+j+1]
        }

        var i=0
        var j=0
        var k=st

        while(i<nr1 && j<nr2){
            if(stg[i]>drt[j]){
                arr[k]=stg[i]
                i++
            }
            else{
                arr[k]=drt[j]
                j++

            }

            k++
        }

        while(i<nr1){
            arr[k]=stg[i]
            i++
            k++
        }

        while(j<nr2){
            arr[k]=drt[j]
            j++
            k++
        }

    }


    fun sortingAlgMerge(arr:MutableList<Int>,st: Int, dr: Int){
        if(st<dr){
            val mid=st + ((dr - st) / 2)
            sortingAlgMerge(arr,st,mid)
            sortingAlgMerge(arr,mid+1,dr)
            merge(arr,st,mid,dr)
        }
    }


    fun partition(arr:MutableList<Int>,st:Int,dr: Int) : Int {
        val pivot=arr[dr]
        var i=st-1
        for(j in st..dr){
            if(arr[j]>pivot){
                i++
                val temp=arr[i]
                arr[i] = arr[j]
                arr[j] = temp
            }
        }
        val temp2=arr[i+1]
        arr[i+1]=arr[dr]
        arr[dr]=temp2

        return (i+1)
    }

    fun sortingAlgQuick(arr:MutableList<Int>,st:Int,dr: Int){
        if(st<dr){
            val pivot=partition(arr,st,dr)
            sortingAlgQuick(arr,st,pivot-1)
            sortingAlgQuick(arr,pivot+1,dr)
        }
    }


    fun printArray(arr:MutableList<Int>){
        for(i in arr){
            println("${i}")
        }
    }
}

fun main(){
    val arr= mutableListOf(40, 8, 11, 2, 99)
    val n=arr.count()-1
    val sorter=Sorter()

    sorter.sortingAlgBubble(arr,n)
    println("Sortat cu Bubble-Sort")
    sorter.printArray(arr)

    val arr2=arr.toMutableList()
    sorter.sortingAlgInsertion(arr2,n)
    println("Sortat cu InsertionSort")
    sorter.printArray(arr2)

    val arr3=arr.toMutableList()
    sorter.sortingAlgSelection(arr3,n)
    println("Sortat cu SelectionSort")
    sorter.printArray(arr3)

    val arr4=arr.toMutableList()
    sorter.sortingAlgMerge(arr4,0,n-1)
    println("Sortat cu MergeSort")
    sorter.printArray(arr4)

    val arr5=arr.toMutableList()
    sorter.sortingAlgQuick(arr5,0,n-1)
    println("Sortat cu QuickSort")
    sorter.printArray(arr5)



}