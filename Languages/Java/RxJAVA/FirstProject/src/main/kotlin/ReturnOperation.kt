import io.reactivex.Observable
import java.util.concurrent.TimeUnit
import kotlin.random.Random

class ReturnOperation {
}

fun main() {
    bufferOperator()
    mapOperator()
    flatMapOperator()
    concatMapOperator()
    switchMapOperator()
    scanOperator()
}

private fun bufferOperator() {
    Observable.fromIterable(0..8)
        .buffer(2, 4)
        .subscribe(::println)
}

private fun mapOperator() {
    Observable.fromIterable(0..3)
        .map { "RxJava : $it" }
        .subscribe(::println)
}

private fun flatMapOperator() {
    Observable.fromIterable(listOf(1, 2, 3, 4, 5, 6))
        .flatMap { original: Int ->
            Observable.just("$original plusplus")
                .delay(Random.nextLong(5), TimeUnit.SECONDS)

        }
        .subscribe(::println)
}

private fun concatMapOperator() {
    Observable.fromIterable(listOf(1, 2, 3, 4, 5, 6))
        .concatMap { original: Int ->
            Observable.just("$original plusplus")
                .delay(Random.nextLong(5), TimeUnit.SECONDS)

        }
        .subscribe(::println)
}

private fun switchMapOperator() {
    Observable.fromIterable(listOf(1, 2, 3, 4, 5, 6))
        .switchMap { original: Int ->
            Observable.just("$original plusplus")
                .delay(Random.nextLong(5), TimeUnit.SECONDS)

        }
        .subscribe(::println)
}

private fun scanOperator() {
    Observable.fromIterable(0..3)
        .scan { t1, t2 -> t1 + t2 }
        .subscribe(::println)
}