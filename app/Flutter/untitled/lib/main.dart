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
        body: SizedBox(
          width: double.infinity, height: 110,
          child: Row(
            children: [
              Container(
                  width: 130,
                  height: 110,
                  margin: EdgeInsets.all(4),
                  child: Image.asset('dog.jpg')
              ),
              Column(
                children: [
                  SizedBox(
                    width: 200,
                    height: 90,
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text('캐논 DSLR 100D (단렌즈, 충전기 16기가 SD포함)', style: TextStyle(fontWeight: FontWeight.w400),),
                        Text('성동구 행당동·끌올 10분 전', style: TextStyle(color: Colors.black26, fontWeight: FontWeight.w400),),
                        Text('210,000원', style: TextStyle(fontWeight: FontWeight.w600),)
                      ],
                    ),
                  ),
                  SizedBox(
                    width: 200,
                    height: 20,
                    child: Row(
                      mainAxisAlignment: MainAxisAlignment.end,
                      children: [
                        Icon(Icons.favorite_border, color: Colors.black54,),
                        Text('4', style: TextStyle(color: Colors.black54),)
                      ],
                    ),
                  )
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}
