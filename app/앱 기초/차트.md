piechart.setUsePercentValues(true)
piechart.description.isEnabled = false
piechart.setExtraOffsets(5f,10f,5f,5f)
piechart.dragDecelerationFrictionCoef = 0.95f
piechart.isDrawHoleEnabled = false
piechart.setHoleColor(R.color.white)
piechart.transparentCircleRadius = 61f
values.add(PieEntry(tansu!!, "탄수화물"))
values.add(PieEntry(nate!!, "나트륨"))
values.add(PieEntry(jiban!!, "지방"))
values.add(PieEntry(vitamin!!, "비타민"))
values.add(PieEntry(danbak!!, "단백질"))
description.text = "영양성분표"
description.textSize = 15f
piechart.description = description
dataset = PieDataSet(values, "성분이름")
dataset.sliceSpace = 3f
dataset.selectionShift = 5f
dataset.setColors(*ColorTemplate.PASTEL_COLORS)

data = PieData((dataset))
data.setValueTextSize(10f)
data.setValueTextColor(R.color.black)
piechart.data = data