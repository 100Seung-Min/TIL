import io.reactivex.*
import io.reactivex.disposables.CompositeDisposable
import io.reactivex.disposables.Disposable
import io.reactivex.subjects.*
import java.lang.IllegalStateException

class HelloRxJava {

}

fun main() {
    Observable // 생산자 : 데이터를 생성하여 전달
        .just("Hello?", "RxJava!?") // 생성연산자
        .map { it.dropLast(1) } // 변환 연산자: 데이터의 가공 (뒷자리 하나를 제거해준다)
        .subscribe(::println) // 소비자: 데이터를 받아서 처리
}