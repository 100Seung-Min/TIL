import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: Text('금호동3가'),
        ),
        body: Container(
          height: 150, padding: EdgeInsets.all(10),
          child: Row(
            children: [
              Flexible(child: Image.asset('dog.jpg'), flex: 3,),
              Flexible(
                flex: 7,
                child: Container(
                  margin: EdgeInsets.fromLTRB(10, 0, 0, 0),
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      Text('캐논 DSLR 100D (단렌즈, 충전기 16기가 SD포함)', style: TextStyle(fontWeight: FontWeight.w400),),
                      Text('성동구 행당동·끌올 10분 전', style: TextStyle(color: Colors.black26, fontWeight: FontWeight.w400),),
                      Text('210,000원', style: TextStyle(fontWeight: FontWeight.w600),),
                      Row(
                        mainAxisAlignment: MainAxisAlignment.end,
                        children: [
                          Icon(Icons.favorite, color: Colors.black54,),
                          Text('4', style: TextStyle(color: Colors.black54),)
                        ],
                      ),
                    ],
                  ),
                ),
              )
            ],
          ),
        ),
      ),
    );
  }
}
