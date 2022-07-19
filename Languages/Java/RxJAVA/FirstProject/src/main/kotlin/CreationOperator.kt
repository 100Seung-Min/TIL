import io.reactivex.Observable
import java.util.concurrent.TimeUnit

class CreationOperator {
}

fun main() {
    createOperator()
    deferOperator()
    fromOperator()
    intervalOperator()
    justOperator()
    rangeOperator()
    repeatOperator()
    timerOperator()
}

fun createOperator() {
    Observable.create<String> { emitter ->
        emitter.onNext("Hello")
        emitter.onNext("RxJava")
        emitter.onComplete()
    }.subscribe { println(it) }
}

fun deferOperator() {
    Observable.defer {
        Observable.create<String> { emitter ->
            emitter.onComplete()
        }
    }.subscribe(::println)
}

fun fromOperator() {
    val items = arrayOf("Hello", "World")
    Observable.fromArray(*items).subscribe(::println)
}

fun intervalOperator() {
    Observable.interval(100, TimeUnit.MILLISECONDS)
        .subscribe(::println)
    Thread.sleep(555)
}

fun justOperator() {
    Observable.just(1, 2, 3).subscribe(::println)
}

fun rangeOperator() {
    Observable.range(3, 2).subscribe(::println)
}

fun repeatOperator() {
    val observable = Observable.just("Hello", "World")
        .repeat(2)
    observable.subscribe(::println)
}

fun timerOperator() {
    println("start : ${System.currentTimeMillis()}")
    Observable.timer(1000, TimeUnit.MILLISECONDS)
        .subscribe {
            println("start : ${System.currentTimeMillis()} + $it")
        }
}

