window.onload = function () 
{ 

    var btn = document.getElementById('btn'); 
    var message_input = document.getElementById('inp'); 
    var name_input = document.getElementById('name'); 
    var message_container = document.getElementById('messages'); 
    var register_form = document.getElementById('register_form'); 
    var chat_section = document.getElementById('chat_section'); 
    var msg_form = document.getElementById('msg_form'); 
    var register_btn = document.getElementById('register_btn'); 
    var user_list = document.getElementById('user_names'); 

    var socket = io.connect('http://localhost:8080'); 


    socket.on('chat message', function (message) 
    {
        console.log(message);
        var display_message = `<div class="panel well">
                                   <h4>Имя: ${message.name}</h4>
                                   <h5>${message.text}</h5>
                               </div>` 
        message_container.innerHTML += display_message;
    });


    socket.on('update user list', function (users) 
    {
        user_list.innerHTML = ''; 
        users.forEach(function(user) 
        {
            var userItem = document.createElement('li');
            userItem.textContent = user;
            user_list.appendChild(userItem);  
        });
    });


    register_btn.onclick = function ()
    {
        var userName = name_input.value.trim();

        if (userName !== "") 
        {
            register_form.style.display = "none";
            chat_section.style.display = "block";
            msg_form.style.display = "flex";  
            socket.emit('register user', { name: userName });  
        } 
        else { alert("Please enter your name!"); }
    }

    btn.onclick = function () 
    {
        var message = message_input.value.trim();
        
        if (message !== "") 
        {
            socket.emit('send message', { text: message });
            message_input.value = ""; 
        }
    }
}
