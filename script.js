document.getElementById('authForm').addEventListener('submit', function(event) {
    event.preventDefault(); // Предотвращаем отправку формы по умолчанию

    const userId = document.getElementById('userId').value;

    // Проверяем, что пользователь ввел ID
    if (!userId) {
        document.getElementById('result').innerText = 'Please enter your unique ID.';
        return;
    }

    // Отправляем GET-запрос на сервер с параметром 'id'
    fetch(`/auth?id=${userId}`)
        .then(response => response.text()) // Получаем ответ как текст
        .then(data => {
            document.getElementById('result').innerHTML = data; // Выводим результат
        })
        .catch(error => {
            document.getElementById('result').innerText = 'An error occurred: ' + error;
        });
});

// Генерация QR-кода при нажатии на кнопку
document.getElementById('generateQR').addEventListener('click', function() {
    const userId = document.getElementById('userId').value;

    if (!userId) {
        document.getElementById('result').innerText = 'Please enter your unique ID.';
        return;
    }

    // Создаем URL для авторизации с уникальным ID
    const authUrl = `http://localhost:8080/auth?id=${userId}`;

    // Генерируем QR-код на основе URL
    QRCode.toCanvas(document.getElementById('qrcode'), authUrl, function (error) {
        if (error) console.error(error);
        console.log('QR code generated!');
    });
});
