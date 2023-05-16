from flask import Flask, request
import logging; log = logging.getLogger('werkzeug')
import socket, time


# The format of request from remote: "curl http://XX.XX.XX.XX:XXXX/Receiver?XXX=XXX"
    # Example: "curl http://10.198.183.14:8080/Receiver?name=MTDoven"
log.disabled = True
# If you want to show all the message or debug this program, set log.disabled=False
def callback(msg:dict):
    """
    A callback function called when receiving a request.
    :param msg: [dict] including messages from request.
    :return: [str/None] the message return to remote.
    """
    for key,value in msg.items():
        print(key, value)
# When receiving a message, callback() will be called


app = Flask(__name__)
@app.route('/Receiver', methods=['POST'])
def Receiver():
    msg = request.values.to_dict()
    print("    Received from:",request.remote_addr,"on",time.asctime())
    _return = callback(msg)
    if not isinstance(_return,str): _return=""
    return _return
if __name__=="__main__":
    port = 8080
    hostname = socket.gethostname()
    local_ip = socket.gethostbyname(hostname)
    print(f"Local IP: {local_ip}:{port}")
    app.run(host='10.198.67.44', port=port)
