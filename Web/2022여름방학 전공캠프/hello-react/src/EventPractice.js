import React,{Component} from 'react';

class EventPractice extends Component {
  state={
    message: ''
  }
    render(){
        return (
            <div>
                <h1>event</h1>
                <input type="text" name='message' placeholder="dd" onChange={(e) => this.setState({message: e.target.value})} value={this.state.message}></input>
                <button onClick={() => {alert(this.state.message)
                this.setState({
                  message: ''
                })
                }}>확인</button>
            </div>
        )
    }
}
export default EventPractice;