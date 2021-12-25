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
        appBar: AppBar(title: Text('앱임'),),
        body: Align(
          alignment: Alignment.center,
          child: Container(
            width: double.infinity, height: 100,
            decoration: BoxDecoration(
              color: Colors.blue,
            ),
            margin: EdgeInsets.fromLTRB(20,20,20,20), padding: EdgeInsets.fromLTRB(20,20,20,20 ),
            child: Row(
              children: [
                Text("이것은 앱입니다", style: TextStyle(color: Colors.red),),
                ElevatedButton(child: Text('버튼'), onPressed: (){})
              ],
            ),
          ),
        )
      )
    );
  }
}
