import io.reactivex.Completable
import io.reactivex.Observable
import io.reactivex.schedulers.Schedulers
import java.io.IOException
import java.util.concurrent.TimeUnit

class Other {
}

fun main() {
    delay()
    doFunction()
    observeOnAndSubscribeOn()
    timeout()
    retry()
    andThen()
}

private fun delay() {
    println(System.currentTimeMillis())
    Observable.just("Hello", "World")
        .delay(1000, TimeUnit.MILLISECONDS)
        .subscribe {
            println(System.currentTimeMillis())
        }
    Thread.sleep(1111)
}

private fun doFunction() {
    Observable.just("Hello", "RxJava")
        .doOnNext { println("doOnNext") }
        .doOnSubscribe { println("doOnSubscribe") }
        .doAfterNext { println("doAfterNext") }
        .doAfterTerminate { println("doAfterTerminate") }
        .doOnEach { println("doOnEach") }
        .doFinally { println("Finally") }
        .doOnComplete { println("doOnComplete") }
        .doOnDispose { println("doOnDispose") }
        .doOnError { println("doOnError") }
        .doOnTerminate { println("doOnTerminate") }
        .subscribe { println("- $it") }
}

private fun observeOnAndSubscribeOn() {
    Observable.just(1, 2)
        .subscribeOn(Schedulers.io())
        .observeOn(Schedulers.computation())
//        .observeOn(AndroidSchedulers.mainThread()) // Android용
        .subscribe(::println)
}

private fun timeout() {
    Observable.just("Hello", "World")
        .delay(3000L, TimeUnit.MILLISECONDS)
        .timeout(2000L, TimeUnit.MILLISECONDS)
        .subscribe((::println), (::println))
    Thread.sleep(4000)
}

private fun retry() {
    Observable.just(1, 2, 3, 4, 5)
        .map { if (it > 4) throw IOException() else it}
        .retry { cnt, t2 ->
            cnt <= 1
        }
        .subscribe((::println), (::println))
}

private fun andThen() {
    Completable.complete()
        .andThen(Completable.complete())
        .subscribe { println("Everything Success") }
}