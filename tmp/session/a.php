<?php

class MySessionHandler implements SessionHandlerInterface
{
    public function open($savePath, $name)
    {
        return true;
    }

    public function read($sessionId)
    {
        return '';
    }

    public function write($sessionId, $data)
    {
        return true;
    }

    public function close()
    {
        return true;
    }

    public function destroy($sessionId)
    {
        return true;
    }

    public function gc($lifetime)
    {
        return true;
    }

}

class MyRenderer implements Nc\Renderer\RendererInterface
{
    public function __construct()
    {
        ob_start();
    }

    public function getHeaders()
    {
        return [];
    }

    public function render()
    {
        echo ob_get_clean();
    }

}


header('Content-type: text/plain; charset=utf-8');

$request = new nc\http\request();
$response = new nc\http\response();

$response->setDefaultCookieOptions([
    'domain' => '.test.dev',
]);

$response->renderer(new MyRenderer());

$sessionName = session_name();

$sessionId = $request->cookie($sessionName);

var_dump(session_status());

if (!$sessionId) {
    // header_remove('Set-Cookie');
    $sessionId = nc\std::uuid();
    $_COOKIE[$sessionName] = $sessionId;
    $response->cookie($sessionName, $sessionId, [
        'expire' => time() + 30,
        'httpOnly' => true,
    ]);
}

session_set_save_handler(new MySessionHandler());
session_start();

var_dump(session_status());
print_R($_COOKIE);

$response();
