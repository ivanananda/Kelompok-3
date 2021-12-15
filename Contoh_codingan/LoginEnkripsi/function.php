<?php

//koneksi
$koneksi = mysqli_connect('localhost','root','','tutorial-login');

//Daftar
if(isset($_POST['register'])){
    //jika tombol register diklik
    $username = $_POST['username'];
    $password = $_POST['password'];

    if($username == '' or $password == ''){
        echo'
                <script>
                alert("Register gagal coy");
                window.location.href="register.php";
                </script>';
    }else{

        //fungsi enskripsi
        $epassword = password_hash($password, PASSWORD_DEFAULT);
         //masuk ke db
        $insert = mysqli_query($koneksi,"INSERT INTO user(username,password) values ('$username','$epassword')");

        if($insert){
            //jika berhasil
                header('location:index.php');
            }else{
            //Jika gagal
                echo'
                <script>
                alert("Register gagal coy");
                window.location.href="register.php";
                </script>';
                }
    }   
    
}

    //Login
    if(isset($_POST['login'])){
        //jika tombol login diklik
        $username = $_POST['username'];
        $password = $_POST['password'];
        $epassword = $_POST['password'];

        //masuk ke db
        $cekdb = mysqli_query($koneksi,"SELECT * FROM user where username='$username' ");
        $hitung = mysqli_num_rows($cekdb);
        $pw =mysqli_fetch_array($cekdb);
        $passwordsekarang = $pw['password'];
    
        if($hitung>0){
            //jika ada
            //verifikasi password
            if(password_verify($password,$passwordsekarang)){
                //jika passwordnya benar 
                header('location:home.php');
            }else{
                //jika passwordnya salah
                echo'
            <script>
                alert("Password Anda Salah");
                window.location.href="register.php";
    
            </script>';
            }           
        }else{
            //Jika gagal
            echo'
            <script>
                alert("Login Gagal");
                window.location.href="register.php";
    
            </script>';
        }
    }
?>