<?php

header('Content-type: text/plain; charset=utf-8');

$request = new nc\http\request();
$response = new nc\http\response();

$sessionName = session_name();

$response->cookie($sessionName, '');

$response();
