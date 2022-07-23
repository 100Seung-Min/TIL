import io.reactivex.Observable
import io.reactivex.functions.BiFunction
import java.util.concurrent.TimeUnit

class CombineOperator {
}

fun main() {
    combineLatestOperator()
    mergeOperator()
    zipOperator()
    startWithOperator()
}

private fun combineLatestOperator() {
    val observable1 = Observable.interval(1000L, TimeUnit.MILLISECONDS)
    val observable2 = Observable.interval(750L, TimeUnit.MILLISECONDS).map { it + 1000 }
    Observable.combineLatest<Long, Long, String>(
        observable1, observable2,
        BiFunction { t1, t2 ->
            "$t1 $t2"
        }
    ).subscribe {
        println(System.currentTimeMillis())
        println(it)
    }
    Thread.sleep(3000)
}

private fun mergeOperator() {
    val observable1 = Observable.interval(0, 1000, TimeUnit.MILLISECONDS).map { "1:$it" }
    val observable2 = Observable.interval(0, 500, TimeUnit.MILLISECONDS).map { "2:$it" }
    val observable = Observable.merge(observable1, observable2)
    observable.subscribe {
        println(it)
    }
}

private fun zipOperator() {
    val observable1 = Observable.just(1, 2, 3, 4, 5, 6, 7)
    val observable2 = Observable.just("a", "b", "c", "d", "e", "f")
    val observable = Observable.zip(
        observable1, observable2,
        BiFunction<Int, String, String> { t1, t2 -> // RxKotlin시 람다로 가능
            "$t1 and $t2"
        })
    observable.subscribe(::println)
}

private fun startWithOperator() {
    Observable.just(1,2,3,4,5)
        .startWith(500)
        .subscribe(::println)
}
