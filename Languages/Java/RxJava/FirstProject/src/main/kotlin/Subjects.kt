import io.reactivex.subjects.AsyncSubject
import io.reactivex.subjects.BehaviorSubject
import io.reactivex.subjects.PublishSubject
import io.reactivex.subjects.ReplaySubject

class Subjects {
}

fun main() {
    publishSubject()
    behaviorSubject()
    replaySubject()
    asyncSubject()
}

private fun publishSubject() {
    val xSubject = PublishSubject.create<Int>()
    xSubject.subscribe { println("첫번째 $it") }
    xSubject.onNext(1)
    Thread.sleep(1000L)
    xSubject.subscribe { println("----두번째 $it") }
    xSubject.onNext(2)
    xSubject.onNext(3)
    Thread.sleep(1000L)
    xSubject.subscribe { println("********세번째 $it") }
    xSubject.onNext(4)
    xSubject.onComplete()
}

private fun behaviorSubject() {
    val xSubject = BehaviorSubject.create<Int>()
    xSubject.subscribe { println("첫번째 $it") }
    xSubject.onNext(1)
    Thread.sleep(1000L)
    xSubject.subscribe { println("----두번째 $it") }
    xSubject.onNext(2)
    xSubject.onNext(3)
    Thread.sleep(1000L)
    xSubject.subscribe { println("********세번째 $it") }
    xSubject.onNext(4)
    xSubject.onComplete()
}

private fun replaySubject() {
    val xSubject = ReplaySubject.create<Int>()
    xSubject.subscribe { println("첫번째 $it") }
    xSubject.onNext(1)
    Thread.sleep(1000L)
    xSubject.subscribe { println("----두번째 $it") }
    xSubject.onNext(2)
    xSubject.onNext(3)
    Thread.sleep(1000L)
    xSubject.subscribe { println("********세번째 $it") }
    xSubject.onNext(4)
    xSubject.onComplete()
}

private fun asyncSubject() {
    val xSubject = AsyncSubject.create<Int>()
    xSubject.subscribe { println("첫번째 $it") }
    xSubject.onNext(1)
    Thread.sleep(1000L)
    xSubject.subscribe { println("----두번째 $it") }
    xSubject.onNext(2)
    xSubject.onNext(3)
    Thread.sleep(1000L)
    xSubject.subscribe { println("********세번째 $it") }
    xSubject.onNext(4)
    xSubject.onComplete()
}