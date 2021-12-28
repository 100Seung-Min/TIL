import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: ShopItem()
    );
  }
}


class ShopItem extends StatelessWidget {
  const ShopItem({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return SizedBox(
      child:Text('안녕'),
    );
  }
}

