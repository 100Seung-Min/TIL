import io.reactivex.Observable
import java.util.concurrent.TimeUnit

class FilteringOperator {
}

fun main() {
    debounceOperator()
    distinctOperator()
    distinctUtilChangeOperator()
    filterOperator()
    ignoreElementsOperator()
    throttleFirstOperator()
    throttleLastOperator()
    skipAndTakeOperator()
}

private fun debounceOperator() {
    Observable.interval(250, TimeUnit.MILLISECONDS)
        .debounce(333, TimeUnit.MILLISECONDS)
        .subscribe(::println)
    Thread.sleep(1000)
}

data class T(val a: Int, val b: Int)

private fun distinctOperator() {
    Observable.just(T(2, 3), T(2, 4), T(1, 5), T(7, -1), T(2, 2))
        .distinct { it.a + it.b }
        .subscribe(::println)
}

private fun distinctUtilChangeOperator() {
    Observable.just(T(2, 3), T(2, 4), T(1, 5), T(7, -1), T(2, 2))
        .distinctUntilChanged { it -> it.a + it.b }
        .subscribe(::println)
}

private fun filterOperator() {
    Observable.just(11, true, "Hello", "Rx", false)
        .ofType(String::class.java)
        .filter { it.length == 2 }
        .subscribe(::println)
}

private fun ignoreElementsOperator() {
    Observable.just(6, 4, 2)
        .ignoreElements()
        .subscribe(::println)
}

private fun throttleFirstOperator() {
    Observable.interval(0, 100, TimeUnit.MILLISECONDS)
        .throttleFirst(250, TimeUnit.MILLISECONDS)
        .subscribe {
            println(System.currentTimeMillis())
            println(it)
        }
    Thread.sleep(1000)
}

private fun throttleLastOperator() {
    Observable.interval(0, 100, TimeUnit.MILLISECONDS)
        .throttleLast(250, TimeUnit.MILLISECONDS)
        .subscribe {
            println(System.currentTimeMillis())
            println(it)
        }
    Thread.sleep(1000)
}

private fun skipAndTakeOperator() {
    Observable.just(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)
        .take(9)
        .skip(2)
        .skipLast(2)
        .takeLast(3)
        .subscribe(::println)
}