# 전공캠프(AI)
---
## [티쳐블 머신](https://teachablemachine.withgoogle.com/)
1. 이미지와 동영상, 포즈를 통해서 학습
#### 사용법
>1. 데이터를 업로드한다.
>2. 학습을 시켜준다.
>3. 테스트를 해본다.
---
## 이용 예시
>[이미지](https://teachablemachine.withgoogle.com/models/CELECs2BI/)
>[이미지2](https://teachablemachine.withgoogle.com/models/myfyi3FhA/)
>[포즈](https://teachablemachine.withgoogle.com/models/uY3XbnhFM/)
```javascript
<div>Teachable Machine Image Model</div>
<button type="button" onclick="init()">Start</button>
<div id="webcam-container"></div>
<div id="label-container"></div>
<script src="https://cdn.jsdelivr.net/npm/@tensorflow/tfjs@1.3.1/dist/tf.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/@teachablemachine/image@0.8/dist/teachablemachine-image.min.js"></script>
<script type="text/javascript">
    // More API functions here:
    // https://github.com/googlecreativelab/teachablemachine-community/tree/master/libraries/image

    // the link to your model provided by Teachable Machine export panel
    const URL = "./my_model/";

    let model, webcam, labelContainer, maxPredictions;

    // Load the image model and setup the webcam
    async function init() {
        const modelURL = URL + "model.json";
        const metadataURL = URL + "metadata.json";

        // load the model and metadata
        // Refer to tmImage.loadFromFiles() in the API to support files from a file picker
        // or files from your local hard drive
        // Note: the pose library adds "tmImage" object to your window (window.tmImage)
        model = await tmImage.load(modelURL, metadataURL);
        maxPredictions = model.getTotalClasses();

        // Convenience function to setup a webcam
        const flip = true; // whether to flip the webcam
        webcam = new tmImage.Webcam(200, 200, flip); // width, height, flip
        await webcam.setup(); // request access to the webcam
        await webcam.play();
        window.requestAnimationFrame(loop);

        // append elements to the DOM
        document.getElementById("webcam-container").appendChild(webcam.canvas);
        labelContainer = document.getElementById("label-container");
        for (let i = 0; i < maxPredictions; i++) { // and class labels
            labelContainer.appendChild(document.createElement("div"));
        }
    }

    async function loop() {
        webcam.update(); // update the webcam frame
        await predict();
        window.requestAnimationFrame(loop);
    }

    // run the webcam image through the image model
    async function predict() {
        // predict can take in an image, video or canvas html element
        const prediction = await model.predict(webcam.canvas);
        for (let i = 0; i < maxPredictions; i++) {
            const classPrediction =
                prediction[i].className + ": " + prediction[i].probability.toFixed(2);
            labelContainer.childNodes[i].innerHTML = classPrediction;
        }
    }
</script>
```
---
## [응용웹](https://ml-app.yah.ac/)
#### 사용법
>1. 티쳐블 머신으로 ai를 만든 후 파일을 다운로드 한다.
>2. 다운로드 한 파일을 업로드 한다.
>3. 원하는 서비스로 코딩을 한다.
---
## 그외의 웹들
>1. [수학공부](https://ko.khanacademy.org/)
>2. [블록코딩](https://code.org/oceans)
>3. [데이터 라벨링](https://www.testworks.co.kr/contents/aiworks.html?gclid=CjwKCAjw47eFBhA9EiwAy8kzNOeo_Pha70w5wWxeVcXLlObVRRwQCh4HNv-yj2cz8PZ43zMOE33U5hoCWxAQAvD_BwE)
>4. [데이터](https://aihub.or.kr/sample_data_board/movie)